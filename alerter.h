#ifndef ALERTER_H
#define ALERTER_H

#define MAX_CELCIUS 45

extern int alertFailureCount;
extern int networkAlertStub(float celcius);
extern float convertingFarenhitToCelcius(float farenheit);
extern void alertInCelcius(float farenheit, int (*fpNetworkAlert)(float));
extern void test_alertInCelcius(float farenheit);
extern void test_envTempAlert(void);

#endif