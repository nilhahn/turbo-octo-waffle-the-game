//
// Created by matze on 11.05.20.
//

#include "Game.h"
#include "../World/Objects/Player.h"
#include "../World/Objects/Skeleton.h"
#include "../World/Objects/BackgroundObject.h"

#include <iostream>

#define PLAYER_ID "player"
#define SKELETON_ID "skeleton"

Game::Game():FPS(60) {
    this->running = false;
    this->window = nullptr;
    this->textureManager = nullptr;
}

bool Game::init() {
    std::string title = "turbo-octo-waffel";

    int windowWidth = 512;
    int windowHeight = 512;
    Vector2D initalCameraPos(0,0);

    this->window = Window::create(title,windowWidth,windowHeight);
    this->camera.init(windowWidth, windowHeight, initalCameraPos);
    this->textureManager = TextureManager::instance(Resource::getResourcePath());

    this->initPlayer();
    this->loadBackgroundTile();
    // scrap this for now (2021-5-5)
    // this->initMonster(0);

    int x = 0;
    int y = 0;
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            chunk[i][j].x = x;
            chunk[i][j].y = y;
            chunk[i][j].w = 64;
            chunk[i][j].h = 64;
            x += 64;
        }
        x = 0;
        y += 64;
    }

    this->running = this->window != nullptr && this->window->getRenderer() != nullptr;
    return this->running;
}

void Game::render() {
    SDL_Renderer* renderer = this->window->getRenderer();
    //SDL_SetRenderDrawColor(renderer, 0,0,0, 255);
    SDL_RenderClear(renderer);

    Vector2D playerPos = this->objects.at(PLAYER_ID)->getPositon();
    auto background = this->background.find("GRASSLAND")->second.get();
    Vector2D position;
    Vector2D incX(64, 0);
    Vector2D incY(0, 64);
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            SDL_Rect currentChunk = chunk[i][j];
            background->setPosition(position);
            int plx = static_cast<int>(playerPos.getX());
            int ply = static_cast<int>(playerPos.getY());
            if(currentChunk.x <= plx && (currentChunk.x + currentChunk.w) > plx &&
                    currentChunk.y <= ply && (currentChunk.y + currentChunk.h) > ply
                    ||
                    currentChunk.x <= (plx + 17) && (currentChunk.x + currentChunk.w) > (plx + 17) &&
                    currentChunk.y <= (ply + 19) && (currentChunk.y + currentChunk.h) > (ply + 19)
                    ||
                    currentChunk.x <= plx && (currentChunk.x + currentChunk.w) > plx &&
                    currentChunk.y <= (ply + 19) && (currentChunk.y + currentChunk.h) > (ply + 19)
                    ||
                    currentChunk.x <= (plx + 17) && (currentChunk.x + currentChunk.w) > (plx + 17) &&
                    currentChunk.y <= ply && (currentChunk.y + currentChunk.h) > ply
            ) {
                background->draw(this->textureManager, this->window->getRenderer());
            }
            position += incX;
        }
        position.setX(0);
        position += incY;
    }

    for(auto iter = this->objects.begin(); iter != this->objects.end(); iter++) {
        auto elem = iter->second.get();
        elem->draw(this->textureManager, this->window->getRenderer());
    }

    SDL_RenderPresent(renderer);
}

void Game::handleEvents(long delta) {
    SDL_Event event;
    SDL_PollEvent(&event);
    if(event.type == SDL_QUIT) {
        this->quit();
    } else {
        this->inputEvent(this->objects.at(PLAYER_ID).get(), delta);
    }
}

bool Game::isRunning() {
    return this->running;
}

void Game::run() {
    long frameStart = 0;
    long frameTime = 0;
    long delayTime = static_cast<long>(1000.00f / static_cast<float>(FPS));

    if(this->init()) {
        while(this->isRunning()) {
            frameStart = SDL_GetTicks();
            this->render();
            this->handleEvents(frameTime);
            this->update(frameTime);
            frameTime = SDL_GetTicks() - frameStart;
            if(frameTime < delayTime) {
                SDL_Delay(frameTime - frameTime);
            }
        }
    }
}

void Game::initPlayer() {
    InitalizationMapper init;

    init.setObjectId(PLAYER_ID);
    init.setInitalPosition(Vector2D(0,0));

    auto idleDrawable = new Drawable("Player_Idle","Knight_Base_idle.png",17,19,4 );

    init.addNewDrawableForState(WorldObject::ObjectState::IDLE, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::LEFT, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::RIGHT, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::UP, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::DOWN, idleDrawable);
    init.setInitalState(WorldObject::ObjectState::IDLE);

    this->objects.insert(std::pair<std::string, std::unique_ptr<WorldObject> >(PLAYER_ID, std::make_unique<Player>(&init)));
}

void Game::loadBackgroundTile() {
    InitalizationMapper init;

    init.setObjectId("GRASSLAND");
    init.setInitalPosition(Vector2D(0,0));

    auto drawable = new Drawable("Grassland","Grassland64x64.png",64, 64,64,64 , 1);

    init.addNewDrawableForState(WorldObject::ObjectState::IDLE, drawable);
    init.setInitalState(WorldObject::ObjectState::IDLE);

    this->background.insert(std::pair<std::string, std::unique_ptr<WorldObject> >("GRASSLAND", std::make_unique<BackgroundObject>(&init)));
}

void Game::inputEvent(WorldObject* object, long deltaMs) {
    int size = 0;
    float x = 0;
    float y = 0;
    const Uint8* keystates = SDL_GetKeyboardState(&size);

    if(object->getState() != WorldObject::DEAD) {
        object->setState(WorldObject::IDLE);

        if(isKeyDown(keystates, SDL_SCANCODE_W)) {
            object->setState(WorldObject::UP);
            y = -0.1f * static_cast<float>(deltaMs);
        } else if(isKeyDown(keystates, SDL_SCANCODE_S)) {
            object->setState(WorldObject::DOWN);
            y = +0.1f * static_cast<float>(deltaMs);
        }

        if(isKeyDown(keystates, SDL_SCANCODE_A)) {
            object->setState(WorldObject::LEFT);
            x = -0.1f * static_cast<float>(deltaMs);
        } else if(isKeyDown(keystates, SDL_SCANCODE_D)) {
            object->setState(WorldObject::RIGHT);
            x = +0.1f * static_cast<float>(deltaMs);
        }
    }

    object->move(Vector2D(x,y));
}

bool Game::isKeyDown(const Uint8* keyStates, SDL_Scancode key) {
    if(keyStates != nullptr) {
        return keyStates[key] == 1;
    }
    return false;
}

void Game::quit(const char* reason) {
    if(reason != nullptr) {
        std::cout << "Application quit due to " << std::endl;
    }
    this->running = false;
}

void Game::initMonster(int monster) {
    if(monster == 0) {
        this->initSkeleton();
    }
}

void Game::initSkeleton() {
    InitalizationMapper init;

    std::string skeletonId = SKELETON_ID;

    init.setObjectId(skeletonId.data());
    init.setInitalPosition(Vector2D(512/2,512/2));

    auto idleDrawable = new Drawable("Skeleton_Idle","Skeleton_Base.png",17,19,1 );

    init.addNewDrawableForState(WorldObject::ObjectState::IDLE, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::LEFT, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::RIGHT, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::UP, idleDrawable);
    init.addNewDrawableForState(WorldObject::ObjectState::DOWN, idleDrawable);
    init.setInitalState(WorldObject::ObjectState::IDLE);

    this->objects.insert(std::pair<std::string, std::unique_ptr<WorldObject> >(skeletonId.data(), std::make_unique<Skeleton>(&init)));
}

void Game::update(long i) {
    Vector2D playerPos = this->objects.at(PLAYER_ID)->getPositon();
   /* Vector2D skeletonPos = this->objects.at(SKELETON_ID)->getPositon();

    if(playerPos.absDistance(skeletonPos) > 2.) {
        Vector2D move = playerPos - skeletonPos;
        move.norm();
        this->objects.at(SKELETON_ID)->move(move.operator*(0.25));
    }
    */
}


