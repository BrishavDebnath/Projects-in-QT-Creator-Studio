#include <QApplication>
#include <QInputDialog>
#include <QLabel>
#include <QWidget>
#include <QString>


double calculateBMI(double weight, double height) {
    // BMI formula: weight (kg) / (height (m) * height (m))
    return weight / (height * height);
}

QString getBMIStatus(double bmi) {
    if (bmi < 18.5) {
        return "Underweight. It's important to gain weight gradually to reach a healthy BMI. Here are some steps to improve your health:\n\n1. Increase calorie intake with nutrient-rich foods like nuts, seeds, and avocados.\n2. Incorporate strength training exercises to build muscle mass.\n3. Consider consulting with a dietitian or nutritionist for personalized advice.";
    } else if (bmi >= 18.5 && bmi < 25.0) {
        return "Normal weight. Congratulations! Maintaining a healthy weight is key to overall health. Here are some steps to stay healthy:\n\n1. Continue with a balanced diet rich in fruits, vegetables, lean proteins, and whole grains.\n2. Engage in regular physical activity, such as walking, swimming, or cycling.\n3. Prioritize sleep and manage stress levels for optimal health.";
    } else if (bmi >= 25.0 && bmi < 30.0) {
        return "Overweight. It's important to take steps to achieve a healthy weight for better health outcomes. Here are some steps to improve your health:\n\n1. Start with small changes in your diet, such as reducing portion sizes and cutting back on sugary beverages.\n2. Increase physical activity by incorporating more exercise into your daily routine.\n3. Set realistic weight loss goals and track your progress over time.";
    } else {
        return "Obese. Obesity can increase the risk of various health problems. It's essential to take action to improve your health. Here are some steps to\nstart your journey towards a healthier lifestyle:\n\n1. Seek support from healthcare professionals, such as a doctor, dietitian, or personal trainer.\n2. Focus on making gradual changes to your diet and lifestyle habits.\n3. Find enjoyable forms of physical activity to incorporate into your daily routine.\n4. Stay motivated and track your progress towards achieving a healthy weight.";
    }
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Get weight and height from user
    double weight = QInputDialog::getDouble(nullptr, "Enter Weight", "Enter your weight (kg):");
    double height = QInputDialog::getDouble(nullptr, "Enter Height", "Enter your height (m):");

    double bmi = calculateBMI(weight, height);

    // Create widget and set properties
    QWidget window;
    window.setWindowTitle("Body Mass Index Calculator");
    window.resize(900, 500); // Larger window size

    // Display the BMI result and suggestion
    QLabel label(&window);
    label.setText(QString("Your BMI: %1\n\n%2").arg(bmi).arg(getBMIStatus(bmi)));
    label.setAlignment(Qt::AlignLeft | Qt::AlignTop); // Align text to the left and top
    label.setGeometry(100, 100, 800, 600); // Set label position and size

    window.show();

    return app.exec();
}


