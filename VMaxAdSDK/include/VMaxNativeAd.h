//
//  VMaxNativeAd.h
//  VMaxAdSDK
//
//  Created by Thejaswini K on 14/09/15.
//  Copyright © 2015 VMax.com. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@class VMaxNativeAd;
@class VMaxAdView;
@class VMaxMediaView;
typedef NS_ENUM(NSUInteger, VMaxNativeAdType) {
    kVMaxNativeAdType_Infeed,
    kVMaxNativeAdType_ContentStream,
    kVMaxNativeAdType_ContentAd,
    kVMaxNativeAdType_AppInstall,
    kVMaxNativeAdType_Express,
    kVMaxNativeAdType_MediaView
};

@protocol VMaxNativeAdDelegate <NSObject>
@optional
- (void)onNativeAdReady:(VMaxAdView*)adView;
- (void)onNativeAdExpand:(VMaxNativeAd *) nativeAd;
- (void)onNativeAdCollapsed:(VMaxNativeAd *) nativeAd;
- (void)onNativeAdLeftApplication:(VMaxNativeAd *)nativeAd;
@end

@interface VMaxAdImage : NSObject

/*!
 @property
 @abstract url of image
 */
@property (nonatomic, copy, readonly) NSURL *url;

/*!
 @property
 @abstract width of the image
 */
@property (nonatomic, assign, readonly) NSInteger width;

/*!
 @property
 @abstract height of the image
 */
@property (nonatomic, assign, readonly) NSInteger height;

/*!
 @property
 @abstract image will be nil if autoloading property is not set true
 */
@property (nonatomic, strong) UIImage* image;

- (instancetype)initWithURL:(NSURL*)url
                              width:(NSInteger)width
                     height:(NSInteger)height;

- (instancetype)initWithUIImage:(UIImage*)image;

- (void)loadImageAsyncWithBlock:(void (^)(UIImage *image))block;

- (void)cancelLoading;


@end

@class VMaxAdView;

@interface VMaxNativeAd : NSObject

/*!
 @property
 @abstract native ad width for admob express native ad
 */
@property (nonatomic, assign) int nativeAdWidth;

/*!
 @property
 @abstract native ad height for admob express native ad
 */
@property (nonatomic, assign) int nativeAdHeight;

/*!
 @property
 @abstract indicates if ad choice icon will display, if NO, one must display an ad indicator as per mediation specs
 */
@property (nonatomic, readonly) BOOL willDisplayAdChoice;

/*!
 @property
 @abstract native ad delegate
 */
@property (weak,nonatomic) id<VMaxNativeAdDelegate> nativeAdDelegate;
/*!
 @property
 @abstract name of the native ad partners
 */
@property (strong,nonatomic,getter=getNativeAdPartner) NSString* nativeAdPartner;

/*!
 @property
 @abstract type of native ad
 */
@property (assign,nonatomic,getter=getNativeAdType) VMaxNativeAdType nativeAdType;

/*!
 @property
 @abstract title
 */
@property (strong,nonatomic,getter=getTitle) NSString* title;

/*!
 @property
 @abstract call to action text
 */
@property (strong,nonatomic,getter=getCtaText) NSString* ctaText;

/*!
 @property
 @abstract objective
 */
@property (strong,nonatomic,getter=getObjective) NSString* objective;

/*!
 @property
 @abstract imageIcon,image of size 48X48
 */
@property (strong,nonatomic,getter=getImageIcon) VMaxAdImage* imageIcon;

/*!
 @property
 @abstract imageIcon,image of size 300X250
 */
@property (strong,nonatomic,getter=getImageMedium) VMaxAdImage* imageMedium;

/*!
 @property
 @abstract imageIcon,image of size 1200X628
 */
@property (strong,nonatomic,getter=getImageMain) VMaxAdImage* imageMain;

/*!
 @property
 @abstract imageIcon,image of size 320X50
 */
@property (strong,nonatomic,getter=getImageBanner) VMaxAdImage* imageBanner;

/*!
 @property
 @abstract imageIcon,image of size 750X750
 */
@property (strong,nonatomic,getter=getImageTile) VMaxAdImage* imageTile;

/*!
 @property
 @abstract number  of likes
 */
@property (strong,nonatomic,getter=getDesc) NSString* desc;

/*!
 @property
 @abstract number  of likes
 */
@property (strong,nonatomic,getter=getRating) NSString* rating;

/*!
 @property
 @abstract number  of likes
 */
@property (strong,nonatomic,getter=getSalePrice) NSString* salePrice;

/*!
 @property
 @abstract number  of likes
 */
@property (strong,nonatomic,getter=getPrice) NSString* price;


/*!
 @property
 @abstract number  of likes
 */
@property (strong,nonatomic,getter=getSponsored) NSString* sponsored;

/*!
 @property
 @abstract number  of likes
 */
@property (strong,nonatomic,getter=getLikes) NSString* likes;

/*!
 @property
 @abstract phone number
 */
@property (strong,nonatomic,getter=getPhone) NSString* phone;

/*!
 @property
 @abstract address
 */
@property (strong,nonatomic,getter=getAddress) NSString* address;

/*!
 @property
 @abstract description
 */
@property (strong,nonatomic,getter=getDesc2) NSString* desc2;

/*!
 @property
 @abstract displayUrl
 */
@property (strong,nonatomic,getter=getDisplayUrl) NSString* displayUrl;

/*!
 @property
 @abstract number of downloads
 */
@property (strong,nonatomic,getter=getDownloadss) NSString* downloads;

/*!
 @property
 @abstract Facebook mediaview
 */
@property (strong,nonatomic,getter=getView) UIView* view;

/*!
 @property
 @abstract vastVideoTag,VMax Vast VideoTag
 */
@property (strong,nonatomic,getter=getVastVideoTag) NSString *vastVideoTag;

/*!
 @property
 @abstract start download the images it is set true.It will be false by default
 */
@property (assign,nonatomic) BOOL autoLoading;

/*!
 @function      setLinkUrl
 @abstract      set Link Url
 @param         linkUrl,linkUrl
 */
-(void) setLinkUrl:(NSString *)linkUrl;
/*!
 @function      setLinkFallback
 @abstract      set linkFallback url
 @param         linkFallback,linkFallback
 */
-(void)setLinkFallback:(NSString *)linkFallback;

/*!
 @function      setLinkClickTrackers:
 @abstract      seting LinkClickTrackers
 @param         linkClickTrackers,linkClickTrackers.
 */
-(void) setLinkClickTrackers:(NSArray *)linkClickTrackers;


/*!
 @function      reportAndHandleAdClick
 @abstract      report Ad Click and Open the link Url if for vmax and inmobi ads
 */
-(void) reportAndHandleAdClick;
/*!
 @function      setImpTrackers:
 @abstract      setting click trackers
 @param         impTrackers,impTrackers.
 @param         view,view which  holds the nativeAd elements.
 */
-(void) setImpTrackers:(NSArray *)impTrackers;


/*!
 @function      registerViewForInteraction:view:listOfViews
 @abstract      registering native ad for interaction
 @param         adView,AdView.
 @param         view,view which  holds the nativeAd elements.
 @param         listOfViews, List of views which should be clickable.
 */
-(void)registerViewForInteraction:(VMaxAdView*)adView view:(UIView*)view listOfViews:(NSArray*)listOfViews;

/*!
 @function      sizeImage:toView
 @abstract      aspect fit an image to a UIImageView
 @param         image,UIImage.
 @param         imageView,UIImageView which  holds the image.
 */
- (void)sizeImage:(UIImage*)image toView:(UIImageView*)imageView;
@end
