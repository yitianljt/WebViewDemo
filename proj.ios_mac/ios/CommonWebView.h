//
//  CommonWebView.h
//  WebViewDemo
//
//  Created by jintao on 14-10-4.
//
//

#ifndef __WebViewDemo__CommonWebView__
#define __WebViewDemo__CommonWebView__


#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <UIKit/UIKit.h>

@interface CommonWebView : UIViewController<UIWebViewDelegate>

-(void) doLoadUrl: (const char*) urlString;
-(void) onClicked:(id)sender;

@end

#endif