//
//  MTRGInstreamAd.h
//  myTargetSDK 4.8.9
//
//  Created by Anton Bulankin on 31.08.16.
//  Copyright © 2016 Mail.ru. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MyTargetSDK/MTRGInstreamAdPlayer.h>

NS_ASSUME_NONNULL_BEGIN

@class MTRGCustomParams;
@class MTRGInstreamAd;
@class UIViewController;

@interface MTRGInstreamAdBanner : NSObject

@property(nonatomic) NSTimeInterval duration;
@property(nonatomic) BOOL allowPause;
@property(nonatomic) BOOL allowClose;
@property(nonatomic) NSTimeInterval allowCloseDelay;
@property(nonatomic) CGSize size;
@property(nonatomic, copy, nullable) NSString *ctaText;

@end

@protocol MTRGInstreamAdDelegate <NSObject>

- (void)onLoadWithInstreamAd:(MTRGInstreamAd *)instreamAd;

- (void)onNoAdWithReason:(NSString *)reason instreamAd:(MTRGInstreamAd *)instreamAd;

@optional

- (void)onErrorWithReason:(NSString *)reason instreamAd:(MTRGInstreamAd *)instreamAd;

- (void)onBannerStart:(MTRGInstreamAdBanner *)banner instreamAd:(MTRGInstreamAd *)instreamAd;

- (void)onBannerComplete:(MTRGInstreamAdBanner *)banner instreamAd:(MTRGInstreamAd *)instreamAd;

- (void)onBannerTimeLeftChange:(NSTimeInterval)timeLeft duration:(NSTimeInterval)duration instreamAd:(MTRGInstreamAd *)instreamAd;

- (void)onCompleteWithSection:(NSString *)section instreamAd:(MTRGInstreamAd *)instreamAd;

- (void)onShowModalWithInstreamAd:(MTRGInstreamAd *)instreamAd;

- (void)onDismissModalWithInstreamAd:(MTRGInstreamAd *)instreamAd;

- (void)onLeaveApplicationWithInstreamAd:(MTRGInstreamAd *)instreamAd;

@end

@interface MTRGInstreamAd : NSObject

@property(nonatomic, weak, nullable) id <MTRGInstreamAdDelegate> delegate;
@property(nonatomic, readonly, nullable) MTRGCustomParams *customParams;
@property(nonatomic) NSUInteger videoQuality;
@property(nonatomic, nullable) id <MTRGInstreamAdPlayer> player;
@property(nonatomic) BOOL fullscreen;
@property(nonatomic) BOOL trackLocationEnabled;
@property(nonatomic) float volume;
@property(nonatomic) NSUInteger loadingTimeout;

+ (void)setDebugMode:(BOOL)enabled;

+ (BOOL)isDebugMode;

- (nullable instancetype)initWithSlotId:(NSUInteger)slotId;

- (void)load;

- (void)pause;

- (void)resume;

- (void)stop;

- (void)skip;

- (void)skipBanner;

- (void)handleClickWithController:(UIViewController *)controller;

- (void)startPreroll;

- (void)startPostroll;

- (void)startPauseroll;

- (void)startMidrollWithPoint:(NSNumber *)point;

- (void)useDefaultPlayer;

- (void)configureMidpointsP:(NSArray<NSNumber *> *)midpointsP forVideoDuration:(NSTimeInterval)videoDuration;

- (void)configureMidpoints:(NSArray<NSNumber *> *)midpoints forVideoDuration:(NSTimeInterval)videoDuration;

- (void)configureMidpointsForVideoDuration:(NSTimeInterval)videoDuration;

- (NSArray<NSNumber *> *)midpoints;

@end

NS_ASSUME_NONNULL_END
