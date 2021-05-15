
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

//   const char string[] = "totoa"; // do not work
    const char *testid= "test_xdrmem_string";

    int ret = xdr_string(&p,  (char **) &testid, strlen(testid));

    Serial.print("xdr_string2 return =");
    Serial.println(ret);

//   xdr_opaque(&p, (char *) string,  strlen(string));
//   unsigned long x = 1234;
//   bool ret = xdr_u_long(&p, &x);

    Serial.print("data =");
    Serial.flush();
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
