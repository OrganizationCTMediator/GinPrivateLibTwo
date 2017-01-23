#
# Be sure to run `pod lib lint GinPrivateLibTwo.podspec' to ensure this is a
# valid spec before submitting.
#
# Any lines starting with a # are optional, but their use is encouraged
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = 'GinPrivateLibTwo'
  s.version          = '0.1.0'
  s.summary          = 'A short description of GinPrivateLibTwo.'
  s.description      = <<-DESC
TODO: Add long description of the pod here.
                       DESC

  s.homepage         = 'https://github.com/<GITHUB_USERNAME>/GinPrivateLibTwo'
  # s.screenshots     = 'www.example.com/screenshots_1', 'www.example.com/screenshots_2'
  s.license          = { :type => 'MIT', :file => 'LICENSE' }
  s.author           = { '穆秋实' => 'gintamatama0912@gmail.com' }
  s.source           = { :git => 'https://github.com/<GITHUB_USERNAME>/GinPrivateLibTwo.git', :tag => s.version.to_s }
  # s.social_media_url = 'https://twitter.com/<TWITTER_USERNAME>'

  s.ios.deployment_target = '8.0'

  s.source_files = 'GinPrivateLibTwo/Classes/openssl/include/*.h' ,
                    'GinPrivateLibTwo/Classes/EncryptUtil/*.{h,m}' ,
                    'GinPrivateLibTwo/Classes/EncryptUtil/SHA1/*.c'


  s.frameworks = 'Security'
  s.library = 'z','crypto','ssl'
  s.vendored_library = 'GinPrivateLibTwo/Classes/openssl/lib/*.a'

  # s.resource_bundles = {
  #   'GinPrivateLibTwo' => ['GinPrivateLibTwo/Assets/*.png']
  # }

  s.public_header_files = 'GinPrivateLibTwo/Classes/EncryptUtil/EncryptUtil.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
