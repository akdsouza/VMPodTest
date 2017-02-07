//
//  VMaxAdSettings.h
//  VMaxAdSDK
//
//  Created by Anup Dsouza on 14/12/16.
//  Copyright © 2016 Vserv.mobi. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface VMaxAdSize : NSObject
+ (float)FULL_WIDTH;
@end

@interface VMaxAdSettings : NSObject
@property (nonatomic, assign) CGSize admobNativeExpressAdSize;
@property (nonatomic, assign) float adScale;
@end
