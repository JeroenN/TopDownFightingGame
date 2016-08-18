#include <iostream>
#include <math.h>
#include <SFML/Graphics.hpp>
#define PI 3.14159265

/* BUTTONS ON THE XBOX CONTROLLER
 * 0 -> A
 * 1 -> B
 * 2 -> X
 * 3 -> Y
 * 4-> LB
 * 5 -> RB
*/
int main()
{
  bool controllerConnected = false;
  const int window_hight= 768;
  const int window_width = 1024;
  float player1X = 400;
  float dashMultiplier=0;
  float player1MovingPercentageX=0;
  float player1MovingPercentageY=0;
  float player1SwordX=0;
  float player1SwordY=0;
  float multiplierSword;
  float hoekSword;
  float player1PositionX =0;
  float player1PositionY =0;
  int positieSword=0;
  //float lineC;
  //float lengthHoekLine;
  float player1Y = 400;
  float dashReady =0;
  float dashNotReady =0;
  //float showPosition=0;
  float playerSpeed = 7;
  float weapon1Rotation =0;
  float player1Rotation=0;
  float swordReady=1;
  float swordSwingTime=0;


                sf::RenderWindow window(
                sf::VideoMode(window_width, window_hight),
                "mt",
                sf::Style::Titlebar | sf::Style::Close);

               window.setFramerateLimit(70);


               if (sf::Joystick::isConnected(0))
               {
                   std::cout<<"Your controller is connected \n";
                   controllerConnected = true;
               }
               else
               {
                   std::cout<<"Please connect the controller \n";
               }

               while(window.isOpen())
                   {
                       sf::Event event;


                       while(window.pollEvent(event))
                       {
                           switch(event.type)
                           {
                           case sf::Event::Closed:
                               window.close();
                               break;
                           default:
                               break;
                           }
                       }
                       if (sf::Joystick::isConnected(0) && controllerConnected ==false)
                       {
                           std::cout<<"You connected the controller \n";
                           controllerConnected = true;
                       }
                       if (!sf::Joystick::isConnected(0) && controllerConnected ==true)
                       {
                           std::cout<<"Please connect your controller \n";
                           controllerConnected = false;
                       }

                       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                       {
                           window.close();
                           return 0;
                       }
                       swordReady +=0.01;
                       if(swordReady>1)
                       {
                           if (sf::Joystick::isButtonPressed(0, 4))
                           {
                           for(int i=0; i<900; ++i)
                           {
                           weapon1Rotation +=i/10;
                           std::cout<<weapon1Rotation << '\n';
                           }
                           std::cout<<"sword";
                           swordReady =0;
                           }
                       }
                       sf::RectangleShape weapon1;


                       sf::RectangleShape player1;
                       player1.setSize(sf::Vector2f(30, 30));
                       player1.setPosition(player1X, player1Y);
                       player1.setOrigin(sf::Vector2f(15,15));
                       player1.setRotation(hoekSword);

                       player1PositionX= player1.getPosition().x;
                       player1PositionY= player1.getPosition().y;

                       weapon1.setSize(sf::Vector2f(70,8));
                       weapon1.setPosition(player1PositionX,player1PositionY);
                       weapon1.setOrigin(sf::Vector2f(0,4));

                       //weapon1.setRotation(45);
                       weapon1.rotate(hoekSword+weapon1Rotation);
                       std::cout<<weapon1Rotation << '\n';



                       //PRECENTAGE MOVING
                       player1MovingPercentageX= sf::Joystick::getAxisPosition(0, sf::Joystick::X)/100;
                       player1MovingPercentageY= sf::Joystick::getAxisPosition(0, sf::Joystick::Y)/100;


                       //player1RstickX = sf::Joystick::getAxisPosition(0, sf::Joystick::U)/100;
                      // player1RstickY = sf::Joystick::getAxisPosition(0, sf::Joystick::R)/100;

                       //Controll dead area for X
                       if(player1MovingPercentageX >0.25 || player1MovingPercentageX < -0.25)
                       {

                           /*
                                    |
                                    |
                              ______|______
                                    |
                                    |   X
                                    |
                           */
                           player1X += player1MovingPercentageX * playerSpeed;
                           if(player1MovingPercentageX>0 && player1MovingPercentageY>0)
                           {
                               if(player1MovingPercentageX > player1MovingPercentageY)
                               {
                                  dashMultiplier=100/player1MovingPercentageX;
                               }
                           }

                           /*
                                    |
                                    |  X
                              ______|______
                                    |
                                    |
                                    |
                           */


                           if(player1MovingPercentageX>0 && player1MovingPercentageY<0)
                                {
                                   if(player1MovingPercentageX > player1MovingPercentageY*-1)

                                {
                                   dashMultiplier=100/player1MovingPercentageX;
                                }
                            }

                           /*
                                    |
                                X   |
                              ______|______
                                    |
                                    |
                                    |
                           */

                           if(player1MovingPercentageX<0 && player1MovingPercentageY<0)
                                {
                                   if(player1MovingPercentageX*-1 > player1MovingPercentageY*-1)
                                   {
                                   dashMultiplier=100/player1MovingPercentageX*-1;

                                   }
                            }

                           /*
                                    |
                                    |
                              ______|______
                                    |
                                 X  |
                                    |
                           */

                           if(player1MovingPercentageX<0 && player1MovingPercentageY>0)
                                {
                                   if(player1MovingPercentageX*-1 > player1MovingPercentageY)
                                   {
                                   dashMultiplier=100/player1MovingPercentageX*-1;

                                   }
                            }

                       }

                      //Controll dead area for Y
                       if(player1MovingPercentageY >0.25 || player1MovingPercentageY <-0.25)
                       {
                           /*
                                    |
                                    |
                              ______|______
                                    |
                                    |   X
                                    |
                           */
                           player1Y += player1MovingPercentageY *playerSpeed;
                           if(player1MovingPercentageX>0 && player1MovingPercentageY>0)
                           {
                               if(player1MovingPercentageX< player1MovingPercentageY)
                               {
                                   dashMultiplier=100/player1MovingPercentageY;

                               }
                           }


                           /*
                                    |
                                    |  X
                              ______|______
                                    |
                                    |
                                    |
                           */
                           if(player1MovingPercentageX>0 && player1MovingPercentageY<0)
                                {
                                   if(player1MovingPercentageX < player1MovingPercentageY*-1)

                                {
                                   dashMultiplier=-100/player1MovingPercentageY;

                                }
                            }

                           /*
                                    |
                                X   |
                              ______|______
                                    |
                                    |
                                    |
                           */

                           if(player1MovingPercentageX<0 && player1MovingPercentageY<0)
                                {
                                   if(player1MovingPercentageX*-1 < player1MovingPercentageY*-1)
                                   {
                                   dashMultiplier=100/player1MovingPercentageY*-1;

                                   }
                            }

                           /*
                                    |
                                    |
                              ______|______
                                    |
                                 X  |
                                    |
                           */

                           if(player1MovingPercentageX<0 && player1MovingPercentageY>0)
                                {
                                   if(player1MovingPercentageX*-1 < player1MovingPercentageY)
                                   {
                                   dashMultiplier=100/player1MovingPercentageY;

                                   }
                            }

                       }
                       dashReady +=0.01;
                       if(dashReady > 1)
                       {
                           if (sf::Joystick::isButtonPressed(0, 5))
                           {
                           player1X += player1MovingPercentageX/100 *dashMultiplier *20;
                           player1Y += player1MovingPercentageY/100 *dashMultiplier *20;
                           dashNotReady +=0.18;
                           }
                           if(dashNotReady >1)
                           {
                                dashReady =0;
                                dashNotReady=0;
                           }
                       }



                       player1SwordX= sf::Joystick::getAxisPosition(0, sf::Joystick::U);
                       player1SwordY= sf::Joystick::getAxisPosition(0, sf::Joystick::R);

                       if(player1SwordX >25 || player1SwordX < -25 || player1SwordY >25 || player1SwordY <-25)
                       {
                               if(player1SwordX>0 && player1SwordY>0)
                               {
                                     multiplierSword= 100.0/player1SwordX;
                                     positieSword =0;
                               }

                               if(player1SwordX<0 && player1SwordY>0)
                               {
                                   multiplierSword= 100.0/player1SwordY;
                                   positieSword = 1;
                               }

                               if(player1SwordX<0 && player1SwordY<0)
                               {
                                   multiplierSword= 100.0/player1SwordX*-1.0;
                                   positieSword = 2;
                               }

                               if(player1SwordX>0 && player1SwordY<0)
                               {
                                   multiplierSword= 100.0/player1SwordY;
                                   positieSword = 3;
                               }


                               //std::cout<<"playerX: "<< player1SwordX <<"\n";
                               //std::cout<<"playerY: "<< player1SwordY <<"\n";



                               switch(positieSword)
                               {
                               case 0 :
                               player1SwordY *=multiplierSword;
                               player1SwordX *=multiplierSword;
                               hoekSword = atan(player1SwordY/100) * 180 / PI;
                               hoekSword +=0;

                               //std::cout<<positieSword<< "\n";
                                   break;
                               case 1 :
                                   player1SwordY *=multiplierSword;
                                   player1SwordX *=multiplierSword *-1;
                                   hoekSword = atan(player1SwordX/100) * 180 / PI;
                                   hoekSword +=90;
                                   //std::cout<<positieSword<< "\n";
                                   break;
                               case 2 :
                                   player1SwordY *=multiplierSword*-1;
                                   player1SwordX *=multiplierSword;
                                   hoekSword = atan(player1SwordY/100) * 180 / PI;
                                   hoekSword +=180;
                                   //std::cout<<positieSword<< "\n";
                                   break;
                               case 3 :
                                   player1SwordY *=multiplierSword;
                                   player1SwordX *=multiplierSword*-1;
                                   hoekSword = atan(player1SwordX/100) * 180 / PI;
                                   hoekSword +=270;
                                   //std::cout<<positieSword<< "\n";
                                   break;

                               }
                       }
                       else
                       {
                            dashMultiplier =0;
                       }


                        //c^2=a^2 + b^2
                        //lineC= player1SwordX * player1SwordX + player1SwordY * player1SwordY;
                        //lineC = sqrt (lineC);
                        //std::cout<<"squareRoot lineC: " << lineC << "\n";
                        //std::cout<<"hoek van zwaard: "<<hoekSword <<"\n";




                   window.clear();
                   window.draw(player1);
                   window.draw(weapon1);
                   window.display();

               }

    return 0;
}
//if(player1RstickX >0.25 || player1RstickX < -0.25)
//{


 /*
  // CHECK THE PRECENTAGE OF THE PLAYER MOVING SPEED
 showPosition +=0.005;
 if (showPosition > 1)
 {
     //std::cout<< "Player X precentage= " << player1MovingPercentageX*100<<  " %\n";
     //std::cout<< "Player Y precentage= " << player1MovingPercentageY *100<< " %\n";
     showPosition =0;
 }
                       showPosition +=0.05;
                          if (showPosition > 1)
                          {
                              showPosition =0;
                          }
 */
