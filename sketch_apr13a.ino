/*
 * test script with Arduino
 */


#include "rpc.h"

void setup() {
    Serial.begin(9600);
    delay(500);
  
    XDR  p;
    char msg[512];

    // set zeros
    for (int i = 0; i < sizeof(msg); ++i)
    {
        msg[i] = 0;
    }

    xdrmem_create(&p, (char *) msg, sizeof(msg), XDR_ENCODE);

    Serial.println("create done.");
    Serial.flush();

    Serial.print("sizeof(*p.x_ops) = ");
    Serial.println(sizeof(*p.x_ops));
    Serial.flush();

    Serial.print("p.x_handy = ");
    Serial.println(p.x_handy);
    Serial.flush();

//   const char test_string[] = "test_xdrmem_string"; // do not work with xdr_string but works with xdr_opaque
    const char *test_string = "test_xdrmem_string";

    int ret = xdr_string(&p,  (char **) &test_string, strlen(test_string));

    Serial.print("ret =");
    Serial.println(ret);
    Serial.flush();

//   xdr_opaque(&p, (char *) test_string,  strlen(test_string));
    
//   unsigned long x = 1234;
//   bool ret = xdr_u_long(&p, &x);

    Serial.print("msg =");
    for (int i = 0; i < 64; ++i)
    {
        Serial.print(msg[i], HEX);
        Serial.print(", ");
    }
    Serial.println();
    Serial.flush();

    pinMode(LED_BUILTIN, OUTPUT);
}

void loop()
{
// check if not crashed
    digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    delay(1000);                       // wait for a second
    digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
    delay(1000);   
}
