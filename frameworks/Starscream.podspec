#
#  Be sure to run `pod spec lint RZ1VNSDK.podspec' to ensure this is a
#  valid spec and to remove all comments including this before submitting the spec.
#
#  To learn more about Podspec attributes see http://docs.cocoapods.org/specification.html
#  To see working Podspecs in the CocoaPods repo see https://github.com/CocoaPods/Specs/
#

Pod::Spec.new do |s|

  s.name         = "Starscream"
  s.version      = "0.1.3"
  s.summary      = "Starscream"
  s.description  = "认真 GMS 依赖的Starscream"

  s.homepage     = "https://github.com/rzrtc/RZGMSDemo_OC.git"
  s.license      = {
    :type => 'Copyright',
    :text => <<-LICENSE
      Copyright (C) 2020 RZ GMS, Inc. All rights reserved.
      LICENSE
  }
  s.platform     = :ios
  s.swift_versions = '5.0'
  s.ios.deployment_target = '9.0'
  s.author       = { "zhongfan" => "fan.zhong@duobei.com" }
  s.source       = { :git => "https://github.com/rzrtc/RZGMSDemo_OC.git", :tag => "#{s.version}" }
  s.vendored_frameworks  = "xcStarscream.framework"
  
end
