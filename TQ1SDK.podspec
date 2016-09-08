#
 # Be sure to run pod lib lint TQ1SDK.podspec to ensure this is a
 # valid spec and remove all comments before submitting the spec.
 #
 # Any lines starting with a # are optional, but encouraged
 #
 # To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
 #
 
 Pod::Spec.new do |s|
 s.name = "TQ1SDK"
 s.version = "3.2.2-test2-esri"
 s.summary = "Library TQ1SDK to implement shingle on projects"
 
 s.homepage = "https://github.com/tq1/taqtile-sdk-ios"
 s.license = { :type => 'Comercial'}
 s.author = { "Taqtile" => "felipe.sabino@taqtile.com" }
 s.source = { :git => "git@github.com:tq1/br-tq1-ios.git", :tag => "3.2.2-test2-esri" }
 
 s.platform = :ios, '8.0'
 s.requires_arc = true
 s.source_files = 'TQ1SDK/Headers/*.h'
 s.vendored_library = 'TQ1SDK/libTQ1SDK.a'
 
 s.library = 'TQ1SDK'
 s.library = 'sqlite3'
 
 #s.framework = 'GeotriggerSDK'
 s.xcconfig = { 'FRAMEWORK_SEARCH_PATHS' => "$(PODS_ROOT)/GeotriggerSDK" , 'OTHER_LDFLAGS' => '-framework GeotriggerSDK', 'LIBRARY_SEARCH_PATHS' => '$(PODS_ROOT)/TQ1SDK'}
 s.dependency 'GeotriggerSDK'
 end
