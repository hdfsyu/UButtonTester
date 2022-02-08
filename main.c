#include <stdint.h>
#include <stdbool.h>
#include <malloc.h>

#include <vpad/input.h>
#include <whb/log_console.h>
#include <whb/log.h>
#include <whb/proc.h>

/*  Note that "DRC" and "Gamepad" both refer to the large tablet controller.
    Calling it a "proto-Switch" or similar will result in me talking at length
    about how good Wind Waker HD is. */

int main(int argc, char** argv) {
    WHBProcInit();
    WHBLogConsoleInit();
    WHBLogPrintf("A Very Cool And Complete Button Tester");
    WHBLogPrintf("now including J O K E S"); /*  Ultimate Semicolon */
    WHBLogConsoleDraw();

    VPADStatus status;
    VPADReadError error;
    bool vpad_fatal = false;

    while (WHBProcIsRunning()) {
    /*  Read button, touch and sensor data from the Gamepad */
        VPADRead(VPAD_CHAN_0, &status, 1, &error);
    /*  Check for any errors */
        switch (error) {
            case VPAD_READ_SUCCESS: {
                break;
            }
            case VPAD_READ_NO_SAMPLES: {
                continue;
            }
        /*  Either our channel was bad, or the controller is. Since this app
            hard-codes channel 0, we can assume something's up with the
            controller - maybe it needs to get repaired? */
            case VPAD_READ_INVALID_CONTROLLER: {
                WHBLogPrint("Hey! The gamepad is probably broken (we cant find it cuz its disconnected) get it repaired (first try re-running the app)");
            /*  Not much point testing buttons for a controller that's not
                actually there */
                vpad_fatal = true;
                break;
            }
            default: {
                WHBLogPrintf("Unknown VPAD error! %08X", error);
                vpad_fatal = true;
                break;
            }
        }
        if (vpad_fatal) break;

    /*  Check the buttons, and log appropriate messages */
        if (status.trigger & VPAD_BUTTON_A) {
            WHBLogPrint("Pressed A!");
        } else if (status.release & VPAD_BUTTON_A) {
            WHBLogPrint("Released A!");
        }
        if (status.trigger & VPAD_BUTTON_B) {
            WHBLogPrintf("Pressed B!");
        } else if (status.release & VPAD_BUTTON_B) {
            WHBLogPrintf("Released B!");
        }
        if (status.trigger & VPAD_BUTTON_Y) {
            WHBLogPrintf("Y did u click Y?");
        } else if (status.release & VPAD_BUTTON_Y){
            WHBLogPrintf("Y did u release Y?");
        }
        if (status.trigger & (VPAD_BUTTON_UP |
            VPAD_STICK_L_EMULATION_UP | VPAD_STICK_R_EMULATION_UP)) {
            WHBLogPrint("Going up! (insert elevator up sounds here)");
        }
        if (status.trigger & (VPAD_BUTTON_LEFT |
            VPAD_STICK_L_EMULATION_LEFT | VPAD_STICK_R_EMULATION_LEFT)) {
            WHBLogPrint("Going... left? I think so");
        }
    /*  Render the log to the screen */
        WHBLogConsoleDraw();
    }
    WHBLogPrint("Quitting and freeing the console");
    WHBLogConsoleDraw();

    WHBLogConsoleFree();
    WHBProcShutdown();

    return 0;
}
