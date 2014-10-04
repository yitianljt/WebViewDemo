//
//  Device_ios.cpp
//  WebViewDemo
//
//  Created by jintao on 14-10-4.
//
//

#include "Device_ios.h"
#include "CommonWebView.h"

void showWebView(std::string url) {
    CommonWebView *view = [[[CommonWebView alloc] init] autorelease];
    [view doLoadUrl:url.c_str()];
    [[UIApplication sharedApplication].keyWindow.rootViewController presentModalViewController:view animated:YES];
}
