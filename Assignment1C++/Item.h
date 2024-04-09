#ifndef ITEM_H
#define ITEM_H

class Item {
private:
    std::string name;
    int price;
    float scrapValueMultiplier;
    float explorerSurvivalChanceMultiplier;
    float operatorSurvivalChanceMultiplier;
    float explorerSaveChance;
    float lootRecoveryMultiplier;

public:
    Item(std::string name, int price, float svm, float escm, float oscm, float esc, float lrm);

    std::string getName();

    int getPrice();

    float getSvm();

    float getEscm();

    float getOscm();

    float getEsc();

    float getLrm();
};

#endif // ITEM_H