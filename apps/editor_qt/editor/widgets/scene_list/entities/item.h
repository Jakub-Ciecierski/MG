#ifndef ITEM_H
#define ITEM_H

#include <QTreeWidget>
#include <gm/rendering/render_body.h>
#include "system/ic_names.h"

#include <widgets/scene_list/entities/item_id.h>

struct Item{
    RenderBody* object;
    QTreeWidgetItem* treeItem;
    Type type;

    std::string displayName;

    std::vector<Item*> children;
    std::vector<Item*> clones;

    Item* parent;

    // NULL if it was not cloned;
    Item* clonedFrom;

    Item();
    Item(RenderBody* object, const Type& type);
    virtual ~Item();

    void setName(std::string name);

    void addChild(Item* child);
    bool removeChild(Item* child);

    Item* makeClone();
    void removeClone(Item* clone);

    void erase(std::vector<Item*>& allItems);

    ItemID getID(QTreeWidget* treeWidget);
    ItemID createID(Item* item, QTreeWidget* treeWidget);
    void createID(Item* item, QTreeWidget* treeWidget,
                  std::vector<int>& id_values);

    bool isClone();
    bool operator==(Item& item) const;
};


struct RootItem : public Item{
    RootItem(){}

    RootItem(const Type& type,
             std::string displayName){
        this->type = type;
        this->treeItem = NULL;
        this->displayName = displayName;
    }
    ~RootItem(){

    }

    void init(QTreeWidget* treeWidget){
        if(treeItem != NULL) return;

        treeItem = new QTreeWidgetItem(treeWidget);
        treeItem->setText(0, QString::fromStdString(displayName));
        treeWidget->addTopLevelItem(treeItem);

        treeItem->setExpanded(true);
    }

    bool isEmpty(){
        if(treeItem == NULL || treeItem->childCount() == 0)
            return true;
        return false;
    }

    void destroy(){
        if(treeItem != NULL){
            delete treeItem;
            treeItem = NULL;
        }
    }
};

#endif // ITEM_H
