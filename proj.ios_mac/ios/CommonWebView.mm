//
//  CommonWebView.cpp
//  WebViewDemo
//
//  Created by jintao on 14-10-4.
//
//

#include "CommonWebView.h"

@interface CommonWebView ()
@end

@implementation CommonWebView

-(void) onClicked:(id)sender {
    [self dismissModalViewControllerAnimated:YES];
}

-(void) doLoadUrl: (const char*) urlString {
    CGSize size=[UIScreen mainScreen].bounds.size;
    
    UIWebView *mWebView = [[[UIWebView alloc] initWithFrame: CGRectMake(0.0f, 40.0f, size.width, size.height-40)] autorelease];
    NSURLRequest *request =[NSURLRequest requestWithURL:[NSURL URLWithString:[NSString stringWithUTF8String:urlString]]];
    [self.view addSubview: mWebView];
    [mWebView loadRequest:request];
    
    UIView *bar=[[[UIView alloc]initWithFrame:CGRectMake(0.0, 0.0, size.width, 40)] autorelease];
    bar.backgroundColor=[UIColor colorWithRed:56.0/255 green:57.0/255 blue:71.0/255 alpha:1.0];
    [self.view addSubview:bar];
    
    UIButton *mBackButton =[[[UIButton alloc] initWithFrame:CGRectMake(0, 0, 75, 40)] autorelease];
    //[mBackButton setBackgroundImage:[UIImage imageNamed:@"back.png"] forState:UIControlStateNormal];
    //[mBackButton setBackgroundImage:[UIImage imageNamed:@"back.png"] forState:UIControlStateNormal];

    [mBackButton setTitle: @"返回" forState: UIControlStateNormal];
    [mBackButton addTarget:self action:@selector(onClicked:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview: mBackButton];
}

@end