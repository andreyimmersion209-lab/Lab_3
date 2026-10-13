/*********************************
 * Автор:    Хан Кирилл          *
 * Задание:  Циклы с ветвлениями *
 * Вариант:  26                  *
 ********************************/

#include <cmath>
#include <iostream>

using namespace std;

int main() {
  const double pi = 3.1415926535;
  const double centimetersInMeter = 100.0;
  const int speedCount = 5;

  double reynoldsLimit = 50000.0;
  double speedList[speedCount] = {1.0, 2.0, 5.0, 10.0, 20.0};

  double cylinderDiameter, cylinderLength, kinematicViscosity;
  double thermalConductivity, temperatureDrop;
  double airSpeed, reynolds, nusselt, heatFlow;

  cout << "d (cm) = ";
  cin >> cylinderDiameter;

  cout << "l (m) = ";
  cin >> cylinderLength;

  cout << "nu (m^2/s) = ";
  cin >> kinematicViscosity;

  cout << "lambda (kcal/(m*s*deg)) = ";
  cin >> thermalConductivity;

  cout << "dt (deg) = ";
  cin >> temperatureDrop;

  cylinderDiameter = cylinderDiameter / centimetersInMeter;

  cout << "w (m/s) Q (kcal/s) Nu Re" << endl;

  for (int speedIndex = 0; speedIndex < speedCount; ++speedIndex) {
    airSpeed = speedList[speedIndex];

    reynolds = airSpeed * cylinderDiameter / kinematicViscosity;

    if (reynolds < reynoldsLimit) {
      nusselt = 0.197 * pow(reynolds, 0.6);
    } else {
      nusselt = 0.023 * pow(reynolds, 0.8);
    }

    heatFlow = pi * cylinderLength * thermalConductivity * nusselt * temperatureDrop;

    cout << airSpeed << " " << heatFlow << " " << nusselt << " " << reynolds << endl;
  }

  return 0;
}
