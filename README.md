# LightSwitch Overlay - PLTW Capstone Project

This project, created as part of the Project Lead the Way (PLTW) Capstone Project, is a smart light switch overlay designed to reduce unnecessary electricity consumption in homes by automating light switch control. The system uses a servo motor, PIR motion sensor, and button input to provide both hands-free and manual control of a traditional light switch. It was developed using a combination of CAD, Arduino, custom soldered components, and a slider mechanism.

[**View Project Portfolio**](https://sites.google.com/spaldinghs.org/illum-innovators/home?authuser=2)  
[**Project Slides**](https://docs.google.com/presentation/d/1SaizZdc4EQiRRDpq9NHYTKKPwRIgYouyuNyXM0Z3mWs/edit?usp=sharing)

## Project Overview

The **LightSwitch Overlay** system allows users to toggle a light switch automatically by detecting motion (via a PIR sensor) or manually via a button press. This product addresses the common problem of homeowners leaving lights on in vacant rooms, leading to unnecessary electricity consumption and higher energy bills.

According to a 2020 Lutron Electronics survey, 90% of American homeowners reported someone in their household frequently leaving lights on. This solution aims to combat that issue in a cost-effective and energy-efficient manner.

<p align="center">
  <img src="https://github.com/roberts1y/lightSwitch/blob/main/pictures/front.jpg" alt="Front View" width="300"/>
  <img src="https://github.com/roberts1y/lightSwitch/blob/main/pictures/side.jpg" alt="Side View" width="300"/>
</p>

### Key Features

- **Motion-Activated Switching**: Automatically flips the switch when motion is detected.
- **Manual Control**: Users can manually toggle the switch with a button press.
- **LED Feedback**: Provides visual cues about the switch’s state (on or off).
- **Easy Installation**: The overlay can be easily installed over any standard light switch without extensive wiring.
- **Cost Efficiency**: Prototype cost $9.65, and with manufacturing optimization, the projected cost is $5.01.

## Components

- **Servo Motor**: Flips the physical light switch through a custom-designed mechanism.
- **PIR Sensor**: Detects motion to trigger the automatic switch toggle.
- **Push Button**: Allows manual control over the switch.
- **Arduino Nano**: The ultra-compact microcontroller responsible for controlling the logic.
- **Soldered Breadboard**: For reliable electrical connections.
- **9V Battery**: Powers the entire overlay system.

## Awards & Recognition

- **Best Overall Award**: Won the "Best Overall" award at an engineering panel against seventy other students.
- **Patent Pending**: The team is pursuing a patent and developing a custom PCB to optimize the design.

<p align="center">
  <img src="https://github.com/roberts1y/lightSwitch/blob/main/pictures/restly.jpg" alt="Mr. Brendan Restly & Robert Snell" width="300"/>
  <img src="https://github.com/roberts1y/lightSwitch/blob/main/pictures/trophy.jpg" alt="Award With Trophy"/>
</p>
  
## How It Works

1. **Motion Detection**: When the PIR sensor detects motion, the servo motor flips the switch to the "on" position. After a set time, it flips back to the "off" position unless overridden by the button.
2. **Manual Override**: Users can press the button to manually toggle the switch, which overrides any motion-based triggers.
3. **Low Power Consumption**: The system is optimized to use minimal power, ensuring longer battery life (projected six-month lifespan after further optimization).

## Future Enhancements

- **Custom PCB**: Aiming for power optimization to extend the product's battery life to six months (from the current prototype’s 20 hours of operation).

## Project Links

- [**Portfolio**](your-portfolio-link)  
- [**Project Slides**](your-slides-link)

<p align="center">
  <img src="https://github.com/roberts1y/lightSwitch/blob/main/pictures/stage.jpg" alt="Audience View of Presentation"/>
</p>

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
