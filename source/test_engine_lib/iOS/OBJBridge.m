//
//  OBJBridge.m
//  TestEngine
//
//  Created by Vladas Zakrevskis on 8/19/17.
//  Copyright © 2017 VladasZ. All rights reserved.
//

#import "OBJBridge.h"

#if IOS

#import <UIKit/UIKit.h>

static UIViewController *topmostController() {
    UIViewController *controller = [UIApplication sharedApplication].keyWindow.rootViewController;
    while (controller.presentedViewController != nil)
        controller = controller.presentedViewController;
    return controller;
}

#elif MAC_OS

#import <AppKit/AppKit.h>

#endif

@interface OBJBridge ()

@end

@implementation OBJBridge

+ (const char *) workDirectoryPath {
    NSString *path = [[NSBundle mainBundle] bundlePath];
    return [path UTF8String];
}

+ (void)showAlert:(const char *)message {
    
    NSString *messageString = [NSString stringWithUTF8String:message];
    
#if IOS
        
    UIAlertController *controller =
    [UIAlertController alertControllerWithTitle:nil
                                        message:messageString
                                 preferredStyle:UIAlertControllerStyleAlert];
    
    [controller addAction:[UIAlertAction actionWithTitle:@"OK" style:UIAlertActionStyleDefault handler:^(UIAlertAction * _Nonnull action) {
        
    }]];
    
    [topmostController() presentViewController:controller animated:YES completion:nil];
    
#elif MAC_OS
    
    NSAlert *alert = [NSAlert new];
    [alert addButtonWithTitle:@"OK"];
    alert.messageText = messageString;
    [alert runModal];
    
#endif
    
}

@end