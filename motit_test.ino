char buf[256];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()> 0)
  {
    int i = 0;
    for(int j = 0; j < 256; j++)buf[j] = 0;

    while(Serial.available() > 0)
    {
      buf[i] = Serial.read();
      i++;

      if(i >= 256)
      {
        break;
      }
    }

    String read(buf);

    int si = read.indexOf('s');
    int ei = read.indexOf('e');
    String data = read.substring(si+1, ei);

    int first_com = data.indexOf(',');

    String x_str = data.substring(0, first_com);

    String non_first = data.substring(first_com+1);

    int second_com = non_first.indexOf(',');

    String y_str = non_first.substring(0, second_com);
    String non_second = non_first.substring(second_com+1);

    int third_com = non_second.indexOf(',');

    String m1_str = non_second.substring(0, third_com);
    String m2_str = non_second.substring(third_com+1);

    int x = x_str.toInt();
    int y = y_str.toInt();
    int m1 = m1_str.toInt();
    int m2 = m2_str.toInt();

    if(m2 == 200)
    {
      digitalWrite(LED_BUILTIN, HIGH);
    }
    else
    {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
