//
//  VMaxCustomAd.h
//  VMaxAdSDK
//
//  Created by Tejus Adiga on 22/10/14.
//  Copyright (c) 2014 VMax.com. All rights reserved.
//

#define VLog(fmt, ...) NSLog((@"VMAX: %s " fmt), __PRETTY_FUNCTION__, ##__VA_ARGS__)

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>

#import "VMaxCustomAdListener.h"

// User Info
extern NSString* const kVMaxCustomAdExtras_Gender;     // NSString can be either kVMaxCustomAdExtras_GenderMale or kVMaxCustomAdExtras_GenderFemale
extern NSString* const kVMaxCustomAdExtras_Email;      // NSString of EMail.
extern NSString* const kVMaxCustomAdExtras_Age;        // NSString of Age.
extern NSString* const kVMaxCustomAdExtras_City;       // NSString City Name.
extern NSString* const kVMaxCustomAdExtras_Keyword;    // NSString Search Keyword.

// Attributes for kVMaxCustomAdExtras_Gender key.
extern NSString* const kVMaxCustomAdExtras_GenderMale;
extern NSString* const kVMaxCustomAdExtras_GenderFemale;

// User Location info
extern NSString* const kVMaxCustomAdExtras_LocationLatitude;   // NSNumber of Double datatype
extern NSString* const kVMaxCustomAdExtras_LocationLongitude;  // NSNumber of Double datatype.
extern NSString* const kVMaxCustomAdExtras_TestMode;  
extern NSString* const kVMaxCustomAdExtras_TestDevices;
extern NSString* const kVMaxCustomAdExtras_CurrencyName;

//Incontent Video Specific
extern NSString* const kVMaxCustomAdExtras_InContentVideoParams;
extern NSString* const kVMaxCustomAdExtras_InContentVideoContentUrl;
extern NSString* const kVMaxCustomAdExtras_InContentVideoContentPlayer;
extern NSString* const kVMaxCustomAdExtras_InContentVideoContentPlayerView;

//Ad Settings
extern NSString* const kVMaxCustomAdExtras_AdSettings;

extern NSString* const kVMaxCustomAdExtras_AdUXType;

//Ad Size
extern NSString* const kVMaxCustomAdExtras_Scale;
extern NSString* const kVMaxCustomAdExtrasAdmob_NativeAdSize;

//Available Ad Sizes
extern NSString* const kVMaxCustomAdAdSize_320x50;
extern NSString* const kVMaxCustomAdSize_728x90;
extern NSString* const kVMaxCustomAdSize_300x250;
extern NSString* const kVMaxCustomAdSize_480x320;
extern NSString* const kVMaxCustomAdSize_320x480;
extern NSString* const kVMaxCustomAdSize_480x800;
extern NSString* const kVMaxCustomAdSize_1024x600;
extern NSString* const kVMaxCustomAdSize_800x480;
extern NSString* const kVMaxCustomAdSize_600x1024;



@protocol VMaxCustomAd <NSObject>
@required

-(void)loadCustomAd:(NSDictionary*)inParams
       withDelegate:(id<VMaxCustomAdListener>)inDelegate
     viewController:(UIViewController*)parentViewController
         withExtras:(NSDictionary*)inExtraInfo;

-(void)showAd;

-(void)invalidateAd;

@optional

- (void)playAd;
- (void)pauseAd;

@end
