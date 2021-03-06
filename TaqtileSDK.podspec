#
 # Be sure to run pod lib lint TaqtileSDK.podspec to ensure this is a
 # valid spec and remove all comments before submitting the spec.
 #
 # Any lines starting with a # are optional, but encouraged
 #
 # To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
 #
 
 Pod::Spec.new do |s|
 s.name = "TaqtileSDK"
 s.version = "2.10.0-dg-no-tracking"
 s.summary = "Library TaqtileSDK to implement shingle on projects"
 
 s.homepage = "https://github.com/tq1/taqtile-sdk-ios"
 s.license = { :type => 'Comercial'}
 s.author = { "Taqtile" => "felipe.sabino@taqtile.com" }
 s.source = { :git => "git@github.com:tq1/br-tq1-ios.git", :tag => "2.10.0-dg-no-tracking" }
 
 s.platform = :ios, '8.0'
 s.requires_arc = true
 s.source_files = 'TaqtileSDK/Headers/*.h'
 s.vendored_library = 'TaqtileSDK/libTaqtileSDK.a'
 
 s.library = 'TaqtileSDK'
 s.library = 'sqlite3'
 end
