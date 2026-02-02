String password = "";
String userInput = "";
boolean changePassword = true;
boolean tryPassword = true;
int firstAsk, WantToChange = 0;
int tries = 0;
int triesAccumulate = 0;

void setup() {
  Serial.begin(9600); // Start serial communication
  Serial.println("");
  pinMode(5, OUTPUT);
}

void loop() 
{
  if (changePassword == true)
  {
    if (firstAsk == 0)
    {
      Serial.println("Enter a password and press Enter:");
      firstAsk = 1;
    }
    if (Serial.available() > 0)
    {
        password = Serial.readString();
        Serial.println("Senha trocada.");
        changePassword = false;
        firstAsk = 0;
    }
  }
  else
  {
    if (firstAsk == 0){
      Serial.println("Password: ");
      tryPassword = true;
      firstAsk = 1;
    }
    if (tryPassword == true)
    {
      if (tries < 3) {
        if (Serial.available() > 0)
        {
          userInput = Serial.readString();
          if (userInput == password)
          {
            Serial.println("Senha correta.");
            Serial.println("");
            tryPassword = false;
            digitalWrite(5, HIGH);
            triesAccumulate = 0;
            WantToChange = 0;
            tries = 0;
          }
          else
          {
            Serial.println("Senha incorreta.");
            tries = tries + 1;
            firstAsk = 0;
          }
        }
      }
      else
      {
        int WaitTime = 5000;
        triesAccumulate = triesAccumulate + 1;
        WaitTime = WaitTime * triesAccumulate;
        Serial.println("Número de tentativas excedida.");
        Serial.print("Tente novamente em ");
        Serial.print(WaitTime/1000);
        Serial.println(" segundos.");
        delay(WaitTime); //Entrega o tempo em segundos.
        tries = 0;
        firstAsk = 0;
      }
    }
    else
    {
      if (WantToChange == 0)
      {
        Serial.println("Quer mudar a senha? [S/N]");
        WantToChange = 1;
      }
      if (Serial.available() > 0)
      {
        String queroTrocar = Serial.readStringUntil('\n');
        queroTrocar.trim();
        queroTrocar.toUpperCase();
        if (queroTrocar == "S")
        {
          digitalWrite(5, LOW);
          changePassword = true;
          password = "";
          firstAsk = 0;
        }
        else if (queroTrocar == "N")
        {
          Serial.println("OK.");
          changePassword = false;
          while (changePassword == false)
          {
            digitalWrite(5, LOW);
            delay(500);
            digitalWrite(5, HIGH);
            delay(500);
          }
        }
        else
        {
          Serial.println("Digite 'S' para mudar de senha e 'N' para manter a senha atual.");
          WantToChange = 0;
        }
      }
    }
  }
}