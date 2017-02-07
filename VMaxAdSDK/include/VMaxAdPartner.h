//
//  VMaxAdPartner.h
//  VMaxAdSDK
//
//  Created by Anup Dsouza on 09/11/16.
//  Copyright © 2016 Vserv.mobi. All rights reserved.
//

#import <Foundation/Foundation.h>

// Ad Partners
extern NSString* const kVMaxAdPartner_AdColony;
extern NSString* const kVMaxAdPartner_Chartboost;
extern NSString* const kVMaxAdPartner_Facebook;
extern NSString* const kVMaxAdPartner_Flurry;
extern NSString* const kVMaxAdPartner_AdX;
extern NSString* const kVMaxAdPartner_Admob;
extern NSString* const kVMaxAdPartner_GoogleIMA;
extern NSString* const kVMaxAdPartner_MilennialMedia;
extern NSString* const kVMaxAdPartner_Pokkt;
extern NSString* const kVMaxAdPartner_InMobi;
extern NSString* const kVMaxAdPartner_UnityAds;
extern NSString* const kVMaxAdPartner_Tapjoy;
extern NSString* const kVMaxAdPartner_Vungle;
extern NSString* const kVMaxAdPartner_VMAX;

@interface VMaxAdPartner : NSObject
@property (nonatomic, readonly) NSString *partnerName;
@property (nonatomic, readonly) NSString *partnerSDKVersion;
@end
