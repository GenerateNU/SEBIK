# SEBIK
The software portion of the safety subsystem will mostly deal with less critical errors as it is assumed that there is still communication between the microcontroller and its peripherals. The main software safety feature exists in the heating state. As the code runs through the state machine every 10 milliseconds or so, it checks if we must switch the band heater on or off based on two conditions. Are we at or above our optimal plastic melting temperature and have we heated at that optimal temperature for the full duration required to melt the pellets. 

Since, this is a software safety feature, there is a chance that it can fail in case we get stuck in some infinite loop due to an edge case or our microcontroller becomes unresponsive. A watchdog timer was used in the main state machine so it could reset the microcontroller in case any of these happened.

The band heater is allowed to operate for 4 minutes as some time is needed to reach the 165°C required to melt the PP. and 3.5 minutes is required for the band heater to completely melt all the PP within the barrel before moving to the next state. 

To do so, the code employs a timer that is initialized at the beginning of the Heating State. This conditional allows the heater to count the amount of time the band heater has been operating at the proper temperature. A watchdog timer will only run when the heater is at an optimal state and count until it reaches 4 minutes of heating time. In real time, this causes the process to run for longer than 4 minutes, however, this is necessary to ensure all the PP is melted.


## Directory Structure:
```
.
|
|───production  # contains files needed for final prototype
|   |
|   |───sebik-eCAD    # contains the KiCAD project
|   └───sebik-src     # contains the code needed for deployment
|
|───testing     # contains files relevant to testing components
|
└───README.md   # this file!
```

## Practice Good Git Hygiene!
1. Only commit files you intended to change
2. Create branches for each feature, and larger branches for each development effort (i.e. ```develop/*```)
3. Check your branch before starting work
4. Pull frequently to avoid conflicts
5. Make Pull Requests when you are ready to merge into a larger branch

## Git Resources

* [Setting up Git](https://fanatical-colossus-434.notion.site/Git-Installation-and-Setup-d07b7d1ab5544424876f9fd3b4a0b312)
* [Intro to Git Crash Course](https://fanatical-colossus-434.notion.site/Crash-Course-Intro-to-Git-809641611da9478b8f9cca8fd97e49fe)

## EE Resources

* [Intro to KiCAD](https://fanatical-colossus-434.notion.site/EE-Crashcourse-Using-Kicad-To-Design-Schematics-8c7091b07237425bae66616ad1f77371)
* [EE Crash Course](https://fanatical-colossus-434.notion.site/EE-Crash-Course-Hardware-2023-c0c7cd5b55cf401e87f8b6c2c8c84336)
