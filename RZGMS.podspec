#
#  Be sure to run `pod spec lint RZ1VNSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "RZGMS"
  s.version      = "1.2.0"
  s.summary      = "RZGMS"
  s.description  = "认真 GMS 的实时消息服务，cocoapods线上版本"

  s.homepage     = "https://github.com/duobeiyun/RZGMSDemo_OC.git"
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright (C) 2021 RZ GMS, Inc. All rights reserved.
      LICENSE
  }
  s.platform     = :ios
  s.pod_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  s.user_target_xcconfig = { 'EXCLUDED_ARCHS[sdk=iphonesimulator*]' => 'arm64'}
  s.swift_versions = '5.0'
  s.ios.deployment_target = '9.0'
  s.author       = { "xiaobing" => "xiaobing.yao@duobei.com" }
  s.source       = { :git => "https://github.com/duobeiyun/RZGMSDemo_OC.git", :tag => "#{s.version}" }
  s.vendored_frameworks  = "frameworks/RZGMS.xcframework", "frameworks/SocketIO.xcframework", "frameworks/Starscream.xcframework"
  
end
