iOS - SDK
=========

## About the SDK
These versions of the SDK are released automatically from our private projects.

## Installation

It's super simple to begin using the SDK. In your Podfile (for example):

    pod 'GeotriggerSDK', :podspec => "https://gist.github.com/mmassaki/f90906719b0b0c891d4d/raw/1a7a099ac16e70cda97cd5730bbeab7eeffbd672/GeotriggerSDK.podspec.json" #this is a fix since the GeotriggerSDK public podspec needs to change in order to be used as a dependency
    pod 'TaqtileSDK', :git => "git@github.com:shingle/taqtile-sdk-ios.git", :tag => "0.2.0" # this tag is an example

for the pod `TaqtileSDK`, you may have the following options for branches and tags:

####  Tags
    - 0.2.0 (stable)
    - 0.2.0-beta (latest version)

## Usage

For now, you can follow the implementation available at our example (SAExample) app. Each version comes with an example app with comments about it's implementation. To download a specific example, simply follow:

    git clone git@github.com:indigotech/shingle-analytics.git --branch develop

## Supported API versions (for this specific SDK)

  - 2.0
  - 2.1
  - 2.14

## TODO

- Add tests
- Add Continuous Integration (Travis)
