#include "HelloWorldScene.h"
#include "Device_ios.h"

USING_NS_CC;

enum {
    kBtnBaiduTag,
    kBtnYoukuTag
};

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();

    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
    auto labelBd = LabelTTF::create("百度一下", "Arial", 24);
    auto itemBaidu = MenuItemLabel::create(labelBd,CC_CALLBACK_1(HelloWorld::menuCallback, this));
    itemBaidu->setTag(kBtnBaiduTag);

    auto labelYK = LabelTTF::create("优酷", "Arial", 24);
    auto itemYK = MenuItemLabel::create(labelYK,CC_CALLBACK_1(HelloWorld::menuCallback, this));
    itemYK->setTag(kBtnYoukuTag);
    
    // create menu, it's an autorelease object
    auto menu = Menu::create(itemBaidu,itemYK, NULL);
    menu->alignItemsVertically();
    menu->setPosition(Size(visibleSize.width/2,visibleSize.height/2));
    this->addChild(menu, 1);


    
    return true;
}


void HelloWorld::menuCallback(Ref* pSender)
{
    Node* node = (Node*)pSender;
    switch (node->getTag()) {
        case kBtnBaiduTag:
            showWebView("http://www.baidu.com");
            break;
        case kBtnYoukuTag:
            showWebView("http://www.youku.com");

            break;

            
        default:
            break;
    }
    
    return ;
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif

    Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}
