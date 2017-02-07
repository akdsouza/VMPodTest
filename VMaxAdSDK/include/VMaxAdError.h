//
//  VMaxAdError.h
//  VMaxAdSDK
//
//  Created by Anup Dsouza on 09/11/16.
//  Copyright © 2016 Vserv.mobi. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString* const kVMaxAdErrorDomain;
extern NSString* const kVMaxAdErrorMessage;
extern NSString* const kVMaxAdErrorDetail;
extern NSString* const kVMaxAdErrorDetailNoFill;
extern NSString* const kVMaxAdErrorDetailAdRequestNotAllowed;
extern NSString* const kVMaxAdErrorDetailSDKInitFailed;
extern NSString* const kVMaxAdErrorDetailNetworkError;
extern NSString* const kVMaxAdErrorDetailAdParamsMissing;
extern NSString* const kVMaxAdErrorDetailRenditionError;
extern NSString* const kVMaxAdErrorDetailParsingFailed;
extern NSString* const kVMaxAdErrorDetailUnknownError;
extern NSString* const kVMaxAdErrorDetailAdExpired;

typedef NS_ENUM (NSInteger, ErrorCode) {
    kVMaxAdErrorNoFill = 1001,
    kVMaxAdErrorAdRequestNotAllowed = 1002,
    kVMaxAdErrorPermissionsMissing = 1003,
    kVMaxAdErrorTimeout = 1004,
    kVMaxAdErrorInternalServerError = 1005,
    kVMaxAdErrorSDKInitFailed = 1006,
    kVMaxAdErrorAdMismatch = 1007,
    kVMaxAdErrorNetworkError = 1008,
    kVMaxAdErrorAdParamsMissing = 1009,
    kVMaxAdErrorAdRenditionFailed = 1010,
    kVMaxAdErrorAdParsingFailed = 1011,
    kVMaxAdErrorUnknownError = 1012,
    kVMaxAdErrorInvalidAdRequest = 1013,
    kVMaxAdErrorAdExpired = 1014
};

/**
 @abstract      Custom VMAX error
 @discussion    Defines a custom error interface for ad related errors
 @property      errorTitle, NSString. A descriptive title for the error.
 @property      code, NSInteger. Query for (VMaxAdError*)instance.code for error code
 @property      localizedDescription, NSString. Query for (VMaxAdError*)instance.localizedDescription for descriptive information about the error.
 */
@interface VMaxAdError : NSError

@property (nonatomic, readonly) NSString *errorTitle;

@end
