#include <stdio.h>
#include <assert.h>
#include "alerter.h"

int alertFailureCount = 0;

int networkAlertStub(float celcius) {
    if( celcius < MAX_CELCIUS )
    {
        printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        // Return 200 for ok
        // Return 500 for not-ok
        // stub always succeeds and returns 200
        return 200;
    }
    else
    {
	printf("ALERT: Temperature is %.1f celcius.\n", celcius);
        return 500;
    }
}
//Art of separation 
float convertingFarenhitToCelcius(float farenheit)
{
    float celcius ;
    celcius = (farenheit - 32) * 5 / 9;
    return celcius;
}
void alertInCelcius(float farenheit, int (*fpNetworkAlert)(float)) 
{
    float celcius  = convertingFarenhitToCelcius(farenheit);
    int returnCode = fpNetworkAlert(celcius);

    if (returnCode != 200) 
    {
        // non-ok response is not an error! Issues happen in life!
        // let us keep a count of failures to report
        // However, this code doesn't count failures!
        // Add a test below to catch this bug. Alter the stub above, if needed.
        alertFailureCount += 0;
    }
    else
    {
        alertFailureCount += 1;
    }

}
void test_alertInCelcius(float farenheit)
{
    alertInCelcius(farenheit, &networkAlertStub);
    printf("%d alerts failed.\n", alertFailureCount);
}

void test_envTempAlert(void)
{
    test_alertInCelcius(400.5);
    test_alertInCelcius(303.6);
    test_alertInCelcius(200);
    test_alertInCelcius(111.2);
    assert(alertFailureCount == 1);
}

int main() 
{
    test_envTempAlert();
    printf("All is well (maybe!)\n");
    return 0;
}