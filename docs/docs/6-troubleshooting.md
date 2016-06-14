# Troubleshooting

## My device is not receiving notifications!
- Check if your device is properly registering for push notifications, if you don't have the right certificates and provisioning profiles, you may even be able to run, but won't be able to register for push notifications. You can check the logs to see if the app is sending `device-token` to the server.
- Check if your app key is correct.
- Check if you are properly connected to the internet and the requests to TQ1 are returning `200` or `204`.
- Check if the push certificate is properly generated.
- Confirm that you are using the correct build environment.

If all these checks pass, you can contact support team via e-mail, or through the admin page.

## I'm receiving normal notifications, but not geonotifications.
- Check if you have properly initiated TQG.
- Check TQG docs to see if you missed something


If all these checks pass, you can contact TQG support team.
