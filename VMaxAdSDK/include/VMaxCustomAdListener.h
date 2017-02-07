//
//  VMaxCustomAdListener.h
//  VMaxAdSDK
//
//  Created by Tejus Adiga on 22/10/14.
//  Copyright (c) 2014 VMax.com. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UIKit/UIKit.h>

@protocol VMaxCustomAd;

@protocol VMaxCustomAdListener <NSObject>
@required

-(void)VMaxCustomAdDidLoadAd:(id<VMaxCustomAd>)inCustomAd;

-(void)VMaxCustomAd:(id<VMaxCustomAd>)inCustomAd
    didFailWithError:(NSError*)outError;

-(void)VMaxCustomAdDidShowAd:(id<VMaxCustomAd>)inCustomAd;

-(void)VMaxCustomAdOnAdClicked:(id<VMaxCustomAd>)inCustomAd;

-(void)VMaxCustomAdWillLeaveApplication:(id<VMaxCustomAd>)inCustomAd;

-(void)VMaxCustomAdDidDismissAd:(id<VMaxCustomAd>)inCustomAd;

-(void)VMaxCustomAd:(id<VMaxCustomAd>)inCustomAd
     didLoadAdInView:(UIView*)outAdView;

@optional
-(void)VMaxCustomAd:(id<VMaxCustomAd>)inCustomAd mediationInfo:(NSDictionary*)info;

-(void)VMaxCustomAdWillPresentOverlay:(id<VMaxCustomAd>)inCustomAd;

-(void)VMaxCustomAdWillDismissOverlay:(id<VMaxCustomAd>)inCustomAd;

-(void)VMaxCustomAd:(id<VMaxCustomAd>)inCustomAd didInterruptRewardVideoWithUserResponseBlock:(void(^)(BOOL))userResponse;

-(void)VMaxCustomAd:(id<VMaxCustomAd>)inCustomAd didFailedToPlaybackRewardVideo:(NSError*)error;

-(void)VMaxCustomAd:(id<VMaxCustomAd>)inCustomAd didCompleteRewardVideo:(NSInteger)rewardAmount;

-(void)VMaxCustomAd:(id<VMaxCustomAd>)inCustomAd didCompleteOfferWall:(NSInteger)rewardAmount;

-(void)VMaxCustomAdDidInteractAd:(id<VMaxCustomAd>)inCustomAd;

-(void)VMaxCustomAdDidFinishInteractAd:(id<VMaxCustomAd>)inCustomAd;

-(void)VMaxCustomAd:(id<VMaxCustomAd>)inCustomAd didComplete:(BOOL)didComplete watchedDuration:(float)watchedDuration totalDuration:(float)totalDuration;

@end
