//
//  VMaxAdSDK.h
//  VMaxAdSDK
//
//  Created by Anup Dsouza on 21/11/16.
//  Copyright © 2016 Vserv.mobi. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 @abstract  The VMaxAdSDKDelegate which notifies on completion of conversions.
 @discussion This method must be implemented in order to be notified of reward on conversion.
 @param reward, The reward to be given.
 */
@protocol VMaxAdSDKDelegate <NSObject>
@required
- (void)onAdReward:(NSInteger)reward;
@end

@class VMaxAdError;

typedef void (^VMaxAdSDKResponseBlock)(VMaxAdError *error);

@interface VMaxAdSDK : NSObject

/**
 @abstract Initializes the VMaxAdSDK with the specified accountKey (mandatory)
 @discussion This method must be called as early as possible in the applications life-cycle.
 Calling this multiple times will have no additional effects."
 @param accountKey, The VMAX accountKey to initialise the SDK.
 @param delegate, The delegate to send callbacks to.
 @param VMaxAdSDKResponseBlock, The response block invoked on completion. Check error for failure, is nil if initialisation succeeded.
 */
+ (void)initWithAccountKey:(NSString *)accountKey delegate:(id<VMaxAdSDKDelegate>)delegate onCompletion:(VMaxAdSDKResponseBlock)completion;

/**
 @abstract Retrieve a string-based representation of the SDK version.
 @discussion The returned string will be in the form of "<Major Version>.<Minor Version>.<External Revision>.<Internal Revision>"
 @return The current VMAX Ad SDK version string.
 */
+ (NSString *)getSDKVersion;

/**
 @abstract Informs if the SDK is ready.
 @discussion The sdk if ready.
 @return BOOL, SDK ready or not.
 */
+ (BOOL)isReady;

/**
 @abstract Informs the SDK of async mediation rewards.
 @discussion The sdk initiates observing to fetch & give rewards.
 @param mediation, id, the mediation to observe.
 */
+ (void)rewardedMediationDidComplete:(id)mediation;

@end
