#ifndef TURBO_OCTO_WAFFLE_THE_GAME_ITEM_H
#define TURBO_OCTO_WAFFLE_THE_GAME_ITEM_H

#include <string>

class Item {
public:
    typedef enum {
        WEAPON, ARMOR, CONSUMABLES, TOOLS, MISC
    } ItemType;

    inline void setValue(int value_) {
        this->value = value_;
    }

    inline int getValue() const {
        return this->value;
    }

    inline void setWeight(int weight_) {
        this->weight = weight_;
    }

    inline int getWeight() const {
        return this->weight;
    }

    inline void setName(const char *name_) {
        this->name = name_;
    }

    inline std::string getName() {
        return this->name;
    }

    inline void setId(const char *id_) {
        this->id = id_;
    }

    inline std::string getId() {
        return this->id;
    }

    inline void setType(ItemType type_) {
        this->type = type_;
    }

    inline ItemType getType() {
        return type;
    }

protected:
    int value;
    int weight;
    std::string id;
    std::string name;
    ItemType type;
};

#endif //TURBO_OCTO_WAFFLE_THE_GAME_ITEM_H
