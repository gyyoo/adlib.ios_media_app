//
//  ADLibSession.h
//  Adlib
//
//  Created by KangTW on 2020/09/08.
//  Copyright © 2020 payco. All rights reserved.
//

#import <Foundation/Foundation.h>

extern NSString * const ADLibSessionDidFinishedLinkNotification;
extern NSString * const ADLibSessionDidFailedLinkNotification;

@class ADLibSession;

@protocol ADLibSessionDelegate <NSObject>

@optional

- (void)ADLibSession:(ADLibSession *)session didFinishedLinkWithUserInfo:(NSDictionary *)userInfo;
- (void)ADLibSession:(ADLibSession *)session didFailedLinkWithError:(NSError *)error;

@end


@interface ADLibSession : NSObject

@property (nonatomic, weak) id<ADLibSessionDelegate> delegate;
@property (nonatomic, copy, readonly) NSString *appKey;

- (instancetype)initWithAdlibKey:(NSString *)appKey;
- (instancetype)initTestSessionWithAdlibKey:(NSString *)appKey;

- (instancetype)initWithAdlibKey:(NSString *)appKey configSession:(ADLibSession *)session;

- (void)linkSession;

+ (void)setDebugMode;

+ (ADLibSession *)sharedSessionForKey:(NSString *)key isTestMode:(BOOL)isTestMode;
+ (void)clearAllSharedSession;

@end
