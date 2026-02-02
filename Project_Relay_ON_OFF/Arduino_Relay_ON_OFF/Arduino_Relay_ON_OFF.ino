String message = "";
char c_data;
void setup() 
{
  Serial.begin(9600);
  pinMode(5,  OUTPUT);
}

void loop() 
{
  if (Serial.available() > 0)
  {
    c_data = Serial.read();
    if (c_data != '\n')     //verifica se há alguma letra
    {
      message = message + c_data;     //Adiciona à mensagem a letra guardada em c_data
    }
    else
    {
      message.toUpperCase();          //Transforma em letras maiúsculas para comparação da String
      if (message == "ON")
      {
        digitalWrite(5, HIGH);
        Serial.println("Bobina ligada!");
        message = "";
      }
      else if (message == "OFF")
      {
        digitalWrite(5, LOW);
        Serial.println("Bobina desligada!");
        message = "";
      }
      else
      {
        Serial.println("Digite 'ON' para ligar a bobina e 'OFF' para desligar a bobina.");
        message = "";
      }
    }
  }
}
