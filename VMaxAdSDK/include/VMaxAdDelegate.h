//
//  VMaxAdDelegate.h
//  VMaxAdSDK
//
//  Copyright (c) 2014 VMax.com. All rights reserved.
//

@class VMaxAdView;

/*!
 @protocol  VMaxAdDelegate
 @abstract  Delegate methods called by VMaxAdView class on events.
 */
@protocol VMaxAdDelegate <NSObject>
@required

/*!
 @function  onAdReady:
 @abstract  Called when an ad is loaded via invocation of loadAd()/cacheAd() API's.
 loadAd() will show the ad immediately whereas cacheAd readies it &
 requires showAd() to show.
 @param     adView, VMaxAdView. The ad view which sent this event.
 */
- (void)onAdReady:(VMaxAdView *)adView;

/*!
 @function  onAdError:error:
 @abstract  Called when the ad view fails to load an ad.
 @param     adView, VMaxAdView. The ad view which sent this event.
 @param     error, NSError. The error which occured.
 */
- (void)onAdError:(VMaxAdView *)adView error:(NSError *)error;

/*!
 @function  onAdDismissed:
 @abstract  Called when an ad is about to be unload from the view.
 @param     adView, VMaxAdView. The ad view which sent this event.
 */
- (void)onAdDismissed:(VMaxAdView *)adView;

/*!
 @function  onAdEnd:completed:
 @abstract  Called when video ad viewing is completed.
 @param     adView, VMaxAdView. The ad view which sent this event.
 @param     completed, BOOL. Video was watched to completion or not.
 @param     reward, NSInteger. Reward on ad completion.
 */
- (void)onAdEnd:(VMaxAdView *)adView completed:(BOOL)completed reward:(NSInteger)reward;


@optional

/*!
 @function  onAdStarted:
 @abstract  Called when an ad is about to be presented in the view.
 @param     adView, VMaxAdView. The ad view which sent this event.
 */
- (void)onAdStarted:(VMaxAdView *)adView;

/*!
 @function  onAdInteracted:
 @abstract  Called when user interacts with an ad via click.
 @param     adView, VMaxAdView. The ad view which sent this event.
 */
- (void)onAdInteracted:(VMaxAdView *)adView;

/*!
 @function  onAdLeftApplication:
 @abstract  Called when an ad click by user will open another app, sending the current
 application to background.
 @param     adView, VMaxAdView. The ad view which sent this event.
 */
- (void)onAdLeftApplication:(VMaxAdView *)adView;

/*!
 @function  onAdExpand:
 @abstract  Called when an ad view transitions to an expanded state.
 Example: On clicking a banner, if an interstitial is displayed.
 @param     adView, VMaxAdView. The ad view which sent this event.
 */
- (void)onAdExpand:(VMaxAdView *)adView;

/*!
 @function  onAdCollapsed:
 @abstract  Called when an ad view transitions back to a normal state.
 @param     adView, VMaxAdView. The ad view which sent this event.
 */
- (void)onAdCollapsed:(VMaxAdView *)adView;

/*!
 @function  onAdInterrupted:
 @abstract  Called when video ad viewing is interrupted.
 @param     adView, VMaxAdView. The ad view which sent this event.
 */
- (void)onAdInterrupted:(VMaxAdView *)adView;

@end
