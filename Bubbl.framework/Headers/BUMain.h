//
//  BUMain.h
//
//  Copyright (c) 2017 Bubbl LTD. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <CoreData/CoreData.h>
#import <CoreLocation/CoreLocation.h>

@interface BUMain : NSObject <CLLocationManagerDelegate>

/* ========================================================*/
/* ========================= PROPERTIES ====================*/
/* ========================================================*/

/*
 *  logLocations
 *
 *  Discussion:
 *      In case you want to debug the user movement you set this value to YES and each location update
 *      will be stored inside the Bubbl Database. You can view the logged locations/movement by using the displayMapDebugView: method.
 *      The default value is NO.
 *      Warning: This will drain the batterry faster. Make sure you don't release the app with this value set to YES.
*/
@property (nonatomic) BOOL logLocations;

/* 
 *  debugMode
 *
 *  Discussion:
 *      Prints detailed information in the console. Defaults to NO.
 *
 */
@property (nonatomic) BOOL debugMode;

/* 
 *  enabled
 *  
 *  Discussion:
 *      Returns the Enabled value from the SDK Configuration. This value cannot be modified on the client side.
 *      To change this value, use the Bubbl Dashboard.
*/
@property (nonatomic, readonly) BOOL enabled;

/*
 *  apiKey
 *
 *  Discussion:
 *      The API Key which was used to initialize the Bubbl SDK.
*/

@property (nonatomic, readonly) NSString *apiKey;

/* ========================================================*/
/* ========================= INITIALIZERS ====================*/
/* ========================================================*/

/*
 *  sharedInstance
 *  
 *  Discussion:
 *      Get the shared instance of the main Bubbl class. Will return nil if the SDK was not configured.
*/

+(instancetype) sharedInstance;

/*
 *  setupWithKey:
 *
 *  Discussion:
 *      Initialize the Bubbl SDK with your API Key. The key must be obtained from the Bubbl Dashboard. Company -> Edit Company Details.
 */
+(instancetype) setupWithKey:(NSString *) apiKey;

/*
 *  setupWithKey:withURLString:
 *
 *  Discussion:
 *      Initialize the Bubbl SDK with your API Key and a custom API URL. 
 *      If you have a custom server you must provide the server URL.
 *      Must be used only if you have a custom Bubbl server.
 */
+(instancetype) setupWithKey:(NSString *) apiKey withURLString:(NSString *) apiURL;


/* ========================================================*/
/* ========================= DISPLAYING DATA ====================*/
/* ========================================================*/

/*
 *  displayActivatedPayloads:
 *
 *  Discussion:
 *      Displays the list of currently activated payloads.
 */
-(void) displayActivatedPayloads;

/*
 *  displayDebugConsoleView:
 *
 *  Discussion:
 *      Displays a view controller with the Bubbl SDK console. Use this to debug potential issues that you have with the SDK.
 */
-(void) displayDebugConsoleView;

/*
 *  displayMapDebugView:
 *
 *  Discussion:
 *      Displays a view controller with the current venues on the map.
 */
-(void) displayDebugMapView;

/*
 *  displayCampaignsView:
 *
 *  Discussion:
 *      Displays a view controller with the current campaigns and payloads inside the Bubbl SDK database.
 */
-(void) displayDebugCampaignsView;

/* ========================================================*/
/* ========================= PRIVACY ====================*/
/* ========================================================*/

/*
 *  displayPrivacyOptions:
 *
 *  Discussion:
 *      Displays the privacy dialog.
 */
+(void) displayPrivacyOptions;

/*
 *  optOut:
 *
 *  Discussion:
 *      Opt out of Bubbl SDK. This will completely disable the Bubbl SDK. To reactivate it you need to call the optIn method or display the privacy options dialog.
 */
-(void) optOut;

/*
 *  optIn:
 *
 *  Discussion:
 *      Enable the Bubbl SDK again, after an opt out call.
 */
-(void) optIn;

/*
 *  didOptOut:
 *
 *  Discussion:
 *      Get the current status privacty status. Will return YES if the user opted out of the Bubbl SDK.
 */
+(BOOL) didOptOut;

/* ========================================================*/
/* ========================= APP DELEGATE CALLS ====================*/
/* ========================================================*/

/*
 *  applicationDidFinishLaunchingWithOptions:
 *
 *  Discussion:
 *      In your App Delegate class, add this call inside application:didFinishLaunchingWithOptions:, this method is used to identify
 *      when the app is launched by touching a Bubbl SDK notification. The Bubbl SDK takes the launchOptions dictionary and identifies 
 *      the currect payload that must be displayed on the screen. 
 *
 */

-(void) applicationDidFinishLaunchingWithOptions:(NSDictionary *)launchOptions;

/*
 *  handleLocalNotification::
 *
 *  Discussion:
 *      In your App Delegate class, add this call inside application:didReceiveLocalNotification:, this method is used to identify
 *      the local notification that where scheduled by the Bubbl SDK.
 *
 *      NOTE: This method will be deprecated by Apple. 
 */
-(void) handleLocalNotification:(UILocalNotification *)notification;


-(void) handleRemoteNotification:(NSDictionary *)notificationJson;

/*
 *  handleRemoteNotificationWithUserInfo:andCompletionHandler: MANDATORY.
 *
 *  Discussion:
 *  In your App Delegate class, add this call inside application:didReceiveRemoteNotification:fetchCompletionHandler:,
 *  this method is used to parse the Bubbl push notification in order to update the local database about its campaigns and payloads.
 * 
 *  The Bubbl SDK heavily relies on the Apple Push Notification Service to update its local database.
 */

-(void) handleRemoteNotificationWithUserInfo: (NSDictionary *) userInfo
                        andCompletionHandler: (void (^)(UIBackgroundFetchResult))completionHandler;


/*
 *  handleBackgroundFetchWithCompletionHandler: MANDATORY.
 *
 *  Discussion:
 *      In your App Delegate class, add this call inside application:performFetchWithCompletionHandler: 
 *      This call will make sure your local database is in sync with the server.
 *
*/
-(void) handleBackgroundFetchWithCompletionHandler: (void (^)(UIBackgroundFetchResult))completionHandler;

/*
 *  registerForRemoteNotificationsWithDeviceToken: MANDATORY.
 *
 *  Discussion:
 *      Call this inside your App Delegate application:didRegisterForRemoteNotificationsWithDeviceToken: method.
 *      This will send the device token to Bubbl servers in order to succesfully receive push notifications.
 *      
 *      Note: Push notifications are heavily used by the Bubbl SDK, failing to register for push notifications 
 *      will cause Bubbl local data to be outdated.
 */
+(void) registerForRemoteNotificationsWithDeviceToken: (NSData *)deviceToken;

@end
