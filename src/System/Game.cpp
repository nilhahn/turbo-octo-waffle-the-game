#include "Game.h"

#include "../World/Objects/Marker.h"

#include <iostream>

#define DEBUG_MARKER_ID "__marker__"
#undef DEBUG_MARKER_ID

#define DEBUG_OUT

Game::Game() : FPS(60) {
    this->running = false;
    this->context = nullptr;
}

bool Game::init() {
    std::string title = "turbo-octo-waffel";

    const int windowWidth{1024};
    const int windowHeight{1024};
    Vector2Df initialCameraPos(0, 0);

    std::string resourcePath = Resource::getResourcePath();
    Window *window = Window::create(title, windowWidth, windowHeight, resourcePath);
    this->context = new Context(window);

    this->camera.init(windowWidth, windowHeight, initialCameraPos);

    this->background.init(*this->context, windowWidth, windowHeight);

    this->initPlayer();
#ifdef DEBUG_MARKER_ID
    this->initMarker();
#endif
    this->initMonster(0);
    this->initMonster(1);

    this->running = this->context->getWindow() != nullptr && this->context->getWindow()->getRenderer() != nullptr;
    return this->running;
}

/**
 * update stuff to the Window
 */
void Game::render(unsigned int delta) {
    SDL_Renderer *renderer = this->context->getWindow()->getRenderer();
    SDL_RenderClear(renderer);

    this->canvas.drawScene(*context, camera, delta);

    SDL_RenderPresent(renderer);
}

void Game::handleEvents(unsigned int delta) {
    SDL_Event event;
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
        this->quit();
    } else {
        this->inputEvent(delta);

#ifdef DEBUG_MARKER_ID
        if (playerState != playerObj->get()->getState()) {
            this->objects.at(DEBUG_MARKER_ID)->setState(playerObj->get()->getState());
        }
#endif
    }
}

bool Game::isRunning() {
    return this->running;
}

void Game::run() {
    Uint32 start{0};
    Uint32 now{0};
    Uint32 nextTime{0};

    const long tick = static_cast<long>(1000.f / static_cast<float>(FPS));
    long delta{0};

    if (this->init()) {
        nextTime += SDL_GetTicks();
        while (this->isRunning()) {
            nextTime += tick;
            start = SDL_GetTicks();
            // attention: with the change to the canvas class the order of this method calls matters
            this->update(tick);
            this->handleEvents(tick);
            this->render(tick);
            now = SDL_GetTicks();
            if (nextTime >= now) {
                delta = (now - start);
                SDL_Delay(tick - delta);
            }
        }
        this->context->getTextureManager()->clear();
    }
}

void Game::initPlayer() {
    PlayerFactory factory;

    this->entities.insert(
            std::pair<std::string, std::unique_ptr<Entity> >(PlayerFactory::entityId,
                                                             std::make_unique<Entity>(factory.createId()))
    );
    factory.createEntity(*this->entities.at(PlayerFactory::entityId).get(), *context, camera);
}

void Game::inputEvent(unsigned int deltaMs) {
    int size = 0;

    const Uint8 *keystates = SDL_GetKeyboardState(&size);
    EntityState::ObjectState state{entities.at(PlayerFactory::entityId)->getProperty<EntityState>()->getState()};
    Vector2Df vector{0.f,0.f};

    const auto player = entities.at(PlayerFactory::entityId);
    if (player->getProperty<EntityState>()->getState() != EntityState::DEAD) {

        if (isKeyDown(keystates, SDL_SCANCODE_W)) {
            state = EntityState::UP;
            vector.setY(-0.1f * static_cast<float>(deltaMs));
        } else if (isKeyDown(keystates, SDL_SCANCODE_S)) {
            state = EntityState::DOWN;
            vector.setY(+0.1f * static_cast<float>(deltaMs));
        }

        if (isKeyDown(keystates, SDL_SCANCODE_A)) {
            state = EntityState::DOWN;
            vector.setX(-0.1f * static_cast<float>(deltaMs));
        } else if (isKeyDown(keystates, SDL_SCANCODE_D)) {
            state = EntityState::RIGHT;
            vector.setX(+0.1f * static_cast<float>(deltaMs));
        }

        const auto currentPos = player->getProperty<HitBox>();

        HitBox nextPos{currentPos->getCornerX(), currentPos->getCornerY(), currentPos->getWidth(), currentPos->getHeight()};
        nextPos.move(vector);
        player->getProperty<EntityState>()->setState(state);

        if (!collide(nextPos)) {
            player->getProperty<HitBox>()->cornerX(nextPos.getCornerX()).cornerY(nextPos.getCornerY());
            camera.move(vector);
        }
    }
}

bool Game::isKeyDown(const Uint8 *keyStates, SDL_Scancode key) {
    if (keyStates != nullptr) {
        return keyStates[key] == 1;
    }
    return false;
}

void Game::quit(const char *reason) {
    if (reason != nullptr) {
        std::cout << "Application quit due to " << std::endl;
    }
    this->running = false;
}

void Game::initMonster(int monster) {
    if (monster == 0) {
        this->initSkeleton();
    } else if (monster == 1) {
        this->initMage();
    }
}

void Game::initSkeleton() {
    SkeletonFactory factory;

    std::string entityId{factory.createId(*context)};

    this->entities.insert(
            std::pair<std::string, std::unique_ptr<Entity> >(entityId, std::make_unique<Entity>(entityId))
    );
    factory.createEntity(*this->entities.at(entityId).get(), *context, camera);
}

void Game::initMage() {
/*    InitalizationMapper init;

    std::string mageId = MAGE_ID;

    init.setObjectId(mageId.data());
    init.setInitalPosition(Vector2Df(64, 64));

    // TODO: initialisation should be done via file input
    auto idleDrawable = new Drawable("Mage_idle", 17, 19, 4);

    this->context->getTextureManager()->addTextureAndId("Mage_idle", "Mage_Base_Idle.png");

    init.addNewDrawableForState(WorldObject::ObjectState::IDLE, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::LEFT, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::RIGHT, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::UP, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::DOWN, idleDrawable);
    init.setInitalState(WorldObject::ObjectState::IDLE);

    this->objects.insert(
            std::pair<std::string, std::unique_ptr<WorldObject> >(mageId.data(), std::make_unique<Skeleton>(&init)));*/
}

void Game::initMarker() {
#ifdef DEBUG_MARKER_ID
    InitalizationMapper init;

    std::string debugMarkerId = DEBUG_MARKER_ID;

    init.setObjectId(debugMarkerId.data());
    init.setInitalPosition(Vector2D(camera.getCenter()->getX() - 64, camera.getCenter()->getY() - 9.5));

    auto drawable = new Drawable("RED_DEBUG_MARKER", "red_arrow.png", 24, 11, 1);

    init.addNewDrawableForState(WorldObject::ObjectState::IDLE, drawable);
    init.setInitalState(WorldObject::ObjectState::IDLE);

    this->objects.insert(std::pair<std::string, std::unique_ptr<WorldObject> >(debugMarkerId.data(),
                                                                               std::make_unique<Marker>(&init)));
#endif
}

void Game::update(unsigned int delta) {
    this->background.update(*context, camera, canvas);
    for (auto iter = this->entities.begin(); iter != this->entities.end(); iter++) {
        const auto elem = iter->second.get();
        HitBox* hitBox = elem->getProperty<HitBox>();
        if(hitBox != nullptr && this->camera.isObjectVisible(hitBox)) {
            this->canvas.addToScene(iter->second);
        }
    }
}

void Game::configure(std::string &configFilePath) {

}

bool Game::collide(HitBox& hitBox) {
    if(!hitBox.isActive()) {
        return false;
    }
    for (const auto & iter : this->canvas.getScene()) {
        if(iter->getEntityId() != PlayerFactory::entityId) {
            auto iterHitBox = iter->getProperty<HitBox>();
            if(iterHitBox->isActive() && iterHitBox->collision(hitBox)) {
                return true;
            }
        }
    }
    return false;
}

