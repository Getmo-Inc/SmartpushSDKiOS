Pod::Spec.new do |s|
  s.name             = 'SmartpushSDK'
  s.version          = '0.0.3'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.homepage         = 'https://github.com/rodrigobusata/SmartpushSDK.git'
  s.authors           = { 'Getmo' => 'contato@getmo.com.br' }
  s.summary          = 'Beta version'
  s.source           = { :git => 'https://github.com/rodrigobusata/SmartpushSDK.git', :tag => '0.0.3'}
  s.source_files = 'SmartpushSDK/Model/HitType.h', 'SmartpushSDK/Model/SmartpushDevice.h', 'SmartpushSDK/Model/SmartpushHit.h', 'SmartpushSDK/Model/SmartpushUser.h', 'SmartpushSDK/SmartpushSDK.h', 'SmartpushNotificationContent/NotificationViewController.h', 'SmartpushNotificationExtensionNotificationService.h'
  s.frameworks = 'QuartzCore', 'UserNotifications', 'UserNotificationsUI'
  s.ios.deployment_target = '6.0'
 
end