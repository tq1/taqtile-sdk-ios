##Classes

Currently, every access to each page, facebook login can be registered and sent to an analytics area at TQ1, and the class that answers to these function is the TQ1Analytics:

```objectivec
@interface TQ1Analytics : NSObject

+ (TQ1Analytics *) shared;

- (void)start;
- (void)resume;
- (void)suspend;
- (void)exit;

- (void)recordEvent:(NSString *)event count:(int)count;
- (void)recordEvent:(NSString *)event segmentation:(NSDictionary *)segmentation count:(int)count;

@end
```

##Events
To send the recorded data, all the app has to do is to record the event and the library takes care of the rest.
Basically, every x recorded events these x events are added to a queue that is then sent to the API.

To record an event one uses the *recordEvent* method. It comes in two versions, but both take the name of the event and a count (amount to add to the existing count). One of them, however, takes an additional parameter "segmentation". "Segmentation" should be an NSDictionary with extra informations about how the data will be shown in the analytics area.
Since TQ1Analytics is an one-for-each-app object, remember to use the shared method to reference it.

```objectivec
NSDictionary *dictionary = [NSDictionary dictionaryWithObject:@"Root" forKey:@"Page name"];
[[TQ1Analytics shared] recordEvent: @"Page views" segmetation: dictionary count:1];
```

To sum it up (in the example):

  - "Page views" - The name of the event
  - "Page name" - The segmentations of the event
  - "Root" - The name of the view that will appear on analytics
  - Count: a integer that will be counted every time this method is called

About when the event queue is sent to the API: it's controlled by a timer defined at TQ1Analytics.
There are four self-explanatory (unless one've never worn a watch) methods to control the timer: *start*, *suspend*, *resume* and *exit*.
Start starts the timer, suspend suspends the timer, resume resumes the timer from when it was suspended and exit destroys the timer.
Only one warning: suspending the timer sends the queue of events to the API independently of the timer, but don't abuse it. It's better for the api to do batch jobs.
