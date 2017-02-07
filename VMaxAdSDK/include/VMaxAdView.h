//
//  VMaxAdView.h
//  VMaxAdSDK
//
//  Copyright (c) 2014 VMax.com. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreLocation/CoreLocation.h>
#import <AVFoundation/AVFoundation.h>

#import "VMaxAdSDK.h"
#import "VMaxAdDelegate.h"
#import "VMaxAdPartner.h"
#import "VMaxNativeAd.h"
#import "VMaxVideoAd.h"
#import "VMaxAdSettings.h"

/*!
 Keys to coustumize the VMaxAdView appearience.
 
 @field VMaxAdView_BackgroundColor:
 Background color of the AdView. Should be UIColor object. This property is applicable for Banner and interstetial ads.
 
 @field VMaxAdView_CloseButtonPosition:
 Close button placement of ads. Should be a NSNumber with VMaxAdCloseButtonPlacement element.
 
 @field VMaxAdView_FrameColor:
 Frame colour of adView. Should be UIColor object. Applicable to both Banner and Interstetial ads.
 
 @field VMaxAdView_Transparence:
 Transperence of adView. Should be NSNumber of float value. Value between 0 and 1. 0 = Full Opaque. 1 = Full Transperent.
 */
extern NSString* const VMaxAdView_BackgroundColor;
extern NSString* const VMaxAdView_CloseButtonPosition;
extern NSString* const VMaxAdView_FrameColor;
extern NSString* const VMaxAdView_Transparence;
extern NSString* const VMaxAdView_AdSize;
extern NSString* const VMaxAdView_Scale;
extern NSString* const VMaxAdViewAdmob_NativeAdSize;


/*!
 @enum      VMaxAdState
 @abstract  Internal states of ads.
 @field     kVMaxAdState_RequestSent, New request for ad has been sent. Yet to receive the responce from adServer.
 @field     kVMaxAdState_Cached, Ad is cached and ready to be displayed. Ads will be inthis state if user
 calls cacheAd and caching is successful.
 @field     kVMaxAdState_CacheFailed, Ad caching is failed. Ads will be in this state when user called
 cacheAd and request to server failed due to some reason. When caching fails
 adView: onAdError:error: is invoked with error.
 @field     kVMaxAdState_Loaded, Ad is loaded and is being displayed.
 @field     kVMaxAdState_Failed, Communication to adserver failed.
 */
typedef NS_ENUM(NSUInteger, VMaxAdState) {
    
    kVMaxAdState_Ad_Not_Requested,
    kVMaxAdState_Ad_Ready,
    kVMaxAdState_Ad_Error,
    kVMaxAdState_Ad_Started,
    kVMaxAdState_Ad_End,
    kVMaxAdState_Ad_Dismissed,
    kVMaxAdState_Ad_Expand,
    kVMaxAdState_Ad_Collapsed,
    kVMaxAdState_Ad_Paused,
    kVMaxAdState_Ad_Resumed,
    kVMaxAdState_Ad_Interacted,
    kVMaxAdState_Ad_Interrupted
};

/*!
 @enum      VMaxTestMode
 @abstract  Test Mode of Adview.
 @field     kVMaxTestMode_NOT_AVAILABLE,
 @field     kVMaxTestMode_TEST_via_ADVID,
 @field     kVMaxTestMode_TEST_via_ID_FROM_NETWORKS,
 @field     kVMaxTestMode_TEST_FOR_ALL_DEVICES,
 */
typedef NS_ENUM(NSUInteger, VMaxTestMode) {
    kVMaxTestMode_NOT_AVAILABLE,
    kVMaxTestMode_TEST_via_ADVID,
    kVMaxTestMode_TEST_via_ID_FROM_NETWORKS,
    kVMaxTestMode_TEST_FOR_ALL_DEVICES,
    
};

/*!
 @enum      VMaxAdCloseButtonPlacement
 @abstract  Placement position of close button on ads. Eventhough closebutton placement is set by the user,
 the ad can override this property and display close button in some other position.
 @field     kVMaxAdCloseButtonPlacement_None, No preference for close button placement.
 @field     kVMaxAdCloseButtonPlacement_TopLeft, Close button placed top left corner of the VMaxAdView.
 @field     kVMaxAdCloseButtonPlacement_TopRight, Close button placed top right corner of the VMaxAdView.
 @field     kVMaxAdCloseButtonPlacement_BottomLeft, Close button placed bottom left corner of the VMaxAdView.
 @field     kVMaxAdCloseButtonPlacement_BottomRight, Close button placed bottom right corner of the VMaxAdView.
 */
typedef NS_ENUM(NSUInteger, VMaxAdCloseButtonPlacement) {
    kVMaxAdCloseButtonPlacement_None,
    kVMaxAdCloseButtonPlacement_TopRight,
    kVMaxAdCloseButtonPlacement_TopLeft,
    kVMaxAdCloseButtonPlacement_BottomRight,
    kVMaxAdCloseButtonPlacement_BottomLeft,
};

/*!
 @enum      VMaxAdUX
 @abstract  The UX Type of the required Ad. User needs to set this property to the SDK.
 @field     kVMaxAdUX_Interstitial, Interstetial UX Type.
 @field     kVMaxAdUX_Banner, Banner UX Type.
 */
typedef NS_ENUM(NSUInteger, VMaxAdUX) {
    kVMaxAdUX_Interstitial,
    kVMaxAdUX_Banner,
    kVMaxAdUX_Native,
    kVMaxAdUX_Billboard,
    kVMaxAdUX_InStreamVideo
};

/*!
 @enum      VMaxAdOrientation
 @abstract  The orientation for the requested ad.
 @field     kVMaxAdOrientation_Adaptive, Ad capable of displaying in any orientation.
 @field     kVMaxAdOrientation_Portrait, Ad capable of displaying in portrait orientation.
 @field     kVMaxAdOrientation_Landscape, Ad capable of displaying in landscape orientation.
 */
typedef NS_ENUM(NSUInteger, VMaxAdOrientation) {
    kVMaxAdOrientation_Adaptive,
    kVMaxAdOrientation_Portrait,
    kVMaxAdOrientation_Landscape
};

/*!
 @enum      VMaxUserGender
 @abstract  Gender property for Optional user property.
 @field     kVMaxUserGender_Male, Gender Male.
 @field     kVMaxUserGender_Female, Gender Female.
 */
typedef NS_ENUM(NSUInteger, VMaxUserGender) {
    kVMaxUserGender_Male   = 'M',
    kVMaxUserGender_Female = 'F'
};

/*!
 @enum      VMaxCountryOption
 @abstract  Country property for Optional user property.
 @field     kVMaxCountries_Exclude, Exclude the countries listed in the country list.
 @field     kVMaxCountries_Include, Include the countries listed in the country list.
 */
typedef NS_ENUM(NSUInteger, VMaxCountryOption) {
    kVMaxCountries_Exclude = 1,
    kVMaxCountries_Allow
};

/*!
 @enum      VMaxAdUser
 @abstract  Optional User property. user needs to set this property for more accurate ad delivery.
 @field     gender, Gender of User.
 @field     age, Age of the user.
 @field     city, City of user.
 @field     email, Mail ID of user.
 */
@interface VMaxAdUser : NSObject
@property (assign, nonatomic) VMaxUserGender   gender;
@property (strong, nonatomic) NSString*         age;
@property (strong, nonatomic) NSString*         city;
@property (strong, nonatomic) NSString*         email;
@end

/*!
 @enum      VMaxAdView
 @abstract  This is the main API interface of VMaxAdSDK. Confirm to VMaxAdDelegate protocol to receive the SDK messages.
 App Developers needs to set the frame of VMaxAdView by calling setFrame:(CGRect)inFrame before any of the Ad request is made.
 Ad Request methods are cacheAd, loadAd and showAd.
 
 For proper display of Ads the Zone ID must be properly set according to the AdType (Interstetial or Banner).
 For interstetial ad type Auto Refresh iof ads are not allowed. Hence any of the refresh methods dosent have any impact.
 
 For banner Ad Type If user wanto to have presize control over the ads he can opt for manual handling of ad caching and display.
 So he can use cacheAd to cache the ad in background. On cache complete SDK notifies user by delegate method
 - (void)onAdReady:(VMaxAdView *)theAdView
 The nuser can display the ad using showAd method. On ad display complete the SDK notifies user by delegate method
 - (void)onAdReady:(VMaxAdView *)theAdView
 For banner Ad type if the user doesent want to hace presize control ever the ad display, he can set the frame of VMaxAdView and call loadAd.
 The user will get callback
 - (void)onAdReady:(VMaxAdView *)theAdView
 when first ad is loaded. Subsequest refreshed ads dosent notifies the user of adRefresh. The default Refresh time is 20 seconds.
 User can set the Refresh time other than this by calling -(void)setRefreshRate:(UInt32)inRefreshIntervalInSeconds
 
 NOTE: Before any ads can be requested the user needs to set the frame of the VMaxADView to display the ad properly.
 */
@interface VMaxAdView : UIView


@property (weak, nonatomic) id<VMaxAdDelegate> delegate;
@property (strong, nonatomic, readonly) NSString *adspotID;
@property (weak, nonatomic) UIViewController *hostController;
@property (assign, nonatomic, readonly) VMaxAdUX adUXType;
@property (nonatomic, readonly) VMaxAdPartner *adPartner;
@property (nonatomic, strong) VMaxAdSettings *adSettings;

- (NSDictionary*)getAdditionalParameters;

/*!
 @function      initWithadspotID: viewController: withAdUXType
 @abstract      Init method to initilize the VMaxAdView. Use initWithRewardedInterstitialAdspotID for Rewarded Interstitial Ads.
 @param         inadspotID, NSString. Zone ID for the Ad. Zone ID can be for Banner or Bilboard.
 @param         inHostViewController, UIViewController. The video controller in which the Ad will be rendered. This will be used for displaying Full screen Billoard ads.
 @param         inAdUXType, VMaxAdUX. Ad UX type from struct VMaxAdUX.
 */
-(id)initWithAdspotID:(NSString*)inAdspotID
       viewController:(UIViewController*)inHostViewController
         withAdUXType:(VMaxAdUX)inAdUXType;

-(id)initWithRewardedInterstitialAdspotID:(NSString*)inAdspotID
                           viewController:(UIViewController*)inHostViewController
                             withAdUXType:(VMaxAdUX)inAdUXType;

/*!
 @function      setCustomVideo:
 @abstract      setting custom video object for customising vast video ads
 @param         customVideoAd,VMaxVideoAd object.
 */
-(void)setCustomVideo:(VMaxVideoAd*)customVideoAd;

/*!
 @function      playAd
 @abstract      Use this method to play incontent video ads if paused.
 */
- (void)playAd;

/*!
 @function      pauseAd
 @abstract      Use this method to pause incontent video ads if playing.
 */
- (void)pauseAd;

/*!
 @function      setVideoControlHidden
 @abstract      Use this method to hide and show incontent video controls
 */
- (void)setVideoControlsHidden:(BOOL)isHidden;
/*!
 @function      setVideoPlayerDetails:
 @abstract      Set the video player details for 'In Content Video' in order to deliver video ads
 @param         contentPlayerContainerView, UIView, the contentPlayer container view.
 */
-(void)setVideoPlayerContainerView:(UIView *)contentPlayerContainerView;
/*!
 @function      setRefresh:
 @abstract      Call this method to enable or disable refresh property. Before setting the refresh use setRefreshRate: to override the default refresh rate of 30 seconds. By default for banner ads refresh is ON and for interstetial ads refresh is always off.
 @param         shouldEnableRefresh, BOOL. If YES Refresh is enabled. If NO Refresh is disabled.
 */
-(void)setRefresh:(BOOL)shouldEnableRefresh;

/*!
 @function      setRefreshRate:
 @abstract      Call this method to set the refresh rate. This overrides the default refresh rate of 30 seconds.
 @param         inRefreshIntervalInSeconds, UInt32. Refresh rate in seconds. Value should be greater than 30 seconds.
 */
-(void)setRefreshRate:(UInt32)inRefreshIntervalInSeconds;

/*!
 @function      pauseRefresh
 @abstract      Pause the auto refreshing of Banner ads.
 */
-(void)pauseRefresh;

/*!
 @function      stopRefresh
 @abstract      Stop the Auto refreshing of Ads. Resume refresh whill have no effect after stoping the refresh.
 */
-(void)stopRefresh;

/*!
 @function      resumeRefresh
 @abstract      Resume the Auto refreshing of Ads. Call this method if pauseRefresh was used to pause the refresh.Resume refresh whill have no effect after stoping the refresh.
 */
-(void)resumeRefresh;

/*!
 @function      setTimeout:
 @abstract      Set the Ad Request timeout. Default timeout is 20 seconds.
 @param         inTimeout, UInt32. Timeout period in seconds.
 */
-(void)setTimeout:(UInt32)inTimeout;

/*!
 @function      setUXType: withConfig:
 @abstract      Set the Configration properties and display properties for Ads.
 @param         inAdUXType, VMaxAdUX. Ad Type. Must be same as passed in init method.
 @param         inConfig, NSDictionary. Dictionary specifying the display properties of Ads. Posible properties are VMaxAdView_BackgroundColor, VMaxAdView_CloseButtonPosition, VMaxAdView_FrameColorVMaxAdView_Transparence;
 */
-(void)setUXType:(VMaxAdUX)inAdUXType
      withConfig:(NSDictionary*)inConfig;

/*!
 @function      setWebViewBackgroundColor:
 @abstract      Set WebView Background color
 @param         backgroundColor, The color that should used to for webView baground.
 */
-(void)setWebViewBackgroundColor:(UIColor*)backgroundColor;
/*!
 @function      cacheAd
 @abstract      Manually cache the ad in background. Ad will not be displayed. On success onAdReady: method will be called by SDK.
 On Failure onAdError:error: will be called by SDK. When this method is called Auto Refresh is automatically disabled.
 */
-(void)cacheAd;

/*!
 @function      cacheAdWithOrientation:
 @abstract      Manually cache the ad in background and request the Ad Server the ad with orientation. Ad will not be displayed. On success onAdReady: method will be called by SDK.
 On Failure onAdError:error: will be called by SDK. When this method is called Auto Refresh is automatically disabled.
 @param         inOrientation, VMaxAdOrientation. Orientation of the required ad.
 */
-(void)cacheAdWithOrientation:(VMaxAdOrientation)inOrientation;

/*!
 @function      loadAd
 @abstract      Loads the Ad and displays it in the ad spot. This will start the Auto refresh property. If user has set the refresh rate then it will use that refresh rate. Else default refresh rate of 30 sec will be used.
 */
-(void)loadAd;

/*!
 @function      loadAdWithOrientation:
 @abstract      Loads the Ad and displays it in the ad spot and request the Ad Server the ad with orientation. This will start the Auto refresh property. If user has set the refresh rate then it will use that refresh rate. Else default refresh rate of 30 sec will be used.
 @param         inOrientation, VMaxAdOrientation. Orientation of the required ad.
 */
-(void)loadAdWithOrientation:(VMaxAdOrientation)inOrientation;

/*!
 @function      showAd
 @abstract      Use this method in conjunction with cacheAd. If the ad is cached in background in responce to cacheAd or cacheAdWithorientation, this method will display the cache ad on screen. For Billboard ads, this method puts full screen overlay on screen.
 */
-(void)showAd;

/*!
 @function      cancelAd
 @abstract      Cancel the request sent to ad server. Call this method if you have called cacheAd and you do not want to display that ad before adViewDidCacheAd is fired.
 */
-(void)cancelAd;

/*!
 @function      getAdState
 @abstract      Retrives the state of the ad.
 @return        VMaxAdState, value from VMaxAdState structure.
 */
-(VMaxAdState)getAdState;

/*!
 @function      setTestMode:withDevices
 @abstract      Set the test mode.
 @param         testMode, VMaxTestMode
 @param         inDeviceIDFAList, NSArray, Test device array.
 */
-(void)setTestMode:(VMaxTestMode)testMode withDevices:(NSArray*)inDeviceIDFAList;


/*!
 @function      setUser:
 @abstract      Set the User information in order to deliver more appropriate ads targetter for the user.
 @param         user, VMaxAdUser, instance of filled VMaxAdUser object.
 */
-(void)setUser:(VMaxAdUser *)user;

/*!
 @function      blockAds:
 @abstract      If true blocks all the adds after this method is called. If false will unblock the ads after this method is called.
 @param         inShouldBlockAds, Bool indicating whether to block the ads.
 */
-(void)blockAds:(BOOL)inShouldBlockAds;

/*!
 @function      setShowAfterSessions:
 @abstract      Blocks the ads for number of sessions input.
 @param         inNoOfSessions, Number of sessions to block.
 */
-(void)showAdsAfterSessions:(int)inNoOfSessions;

/*!
 @function      blockCountries:blockOrAllow:shouldRequestAdIfMCCUnawailable:
 @abstract      Blocks the ads cased on countries.
 @param         inCountryList, List of countries to block the ads of type VMaxCountry mentioned in VMaxCountryCodex.h.
 @param         inAllowOrBlock, option from VMaxCountryOption. Block will block the counties in the country list and allow will allow only the countries in the country list.
 @param         inShouldRequest, YES if ad to be requested if MCC is unawailable.
 */
-(void)blockCountries:(NSArray*)inCountryList blockOrAllow:(VMaxCountryOption)inAllowOrBlock shouldRequestAdIfMCCUnawailable:(BOOL)inShouldRequest;

/*!
 @function      setSection:
 @abstract      setting section
 @param         section, Section
 */
-(void) setSection:(NSString*)section;
/*!
 @function      disableOffline:
 @abstract      Disables the App access when offline. If set to YES then SDK will prompt an allert whenever internet connection is not awailable.
 To access the App the user has to either enable the internet connection or Quit the app.
 @param         inShouldDisableoffline, YES to block the App access while offline.
 */
-(void)disableOffline:(BOOL)inShouldDisableOffline;

/*!
 @function      userDidIAP:
 @abstract      User Did IAP
 @param         inDidIAP, YES/NO.
 */
-(void)userDidIAP:(BOOL)inDidIAP;

/*!
 @function      userDidIncent:
 @abstract      User Did Incent
 @param         inDidIncent, YES/NO.
 */
-(void)userDidIncent:(BOOL)inDidIncent;

/*!
 @function      setLanguageOfArticle:
 @abstract      Sets the Language of Article.
 @param         inlanguageofArticle, Language of Article.
 */
-(void)setLanguageOfArticle:(NSString*)inlanguageofArticle;
/*!
 @function      setKeyword:
 @abstract      Sets the setKeyword
 @param         keyword, Keyword
 */
-(void)setKeyword:(NSString*)keyword;
/*!
 @function      setCustomData:
 @abstract      Sets the CustomData
 @param         customData, CustomData
 */
-(void)setCustomData:(NSDictionary*)customData;

/*!
 @function      setContentURL:
 @abstract      Sets the contentUrl
 @param         contentUrl, contentUrl
 */
- (void)setContentURL:(NSString*)contentUrl;

/**
 * Provide the user's location to the SDK for targetting purposes.
 * @param location: The location of the user
 */
+(void)setLocation:(CLLocation*)location;
/*!
 @function      getNativeAd
 @abstract      Retrive NativeAd object
 @return        NativeAd, object got from the json resposne
 */
-(VMaxNativeAd*)getNativeAd;
/*!
 @function      getRawVASTMarkup
 @abstract      Retrive VastAdO object
 @return        VastAd Data String
 */
-(NSString*)getMarkup;
/*!
 @function      setCustomVideoIsFullscreen
 @abstract      Notify adview is displaying fullscreen (on/off) in pre-roll
 */
- (void)setCustomVideoIsFullscreen:(BOOL)isFullscreen;
@end
