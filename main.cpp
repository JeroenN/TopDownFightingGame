#include <iostream>
//#include <SFML/Joystick.hpp>
//#define X360_CONTROLLER_HPP
#include <SFML/Graphics.hpp>


/* BUTTONS ON THE XBOX CONTROLLER
 * 0 -> A
 * 1 -> B
 * 2 -> X
 * 3 -> Y
 * 4-> LB
 * 5 -> LT
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
  float player1Y = 400;
  float dashReady =0;
  float dashNotReady =0;
  //float showPosition=0;
  float playerSpeed = 7;


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

                       sf::RectangleShape player1;
                       player1.setSize(sf::Vector2f(30, 30));
                       player1.setPosition(player1X, player1Y);
                       player1.setOrigin(sf::Vector2f(0,0));



                       //PRECENTAGE MOVING
                       player1MovingPercentageX= sf::Joystick::getAxisPosition(0, sf::Joystick::X)/100;
                       player1MovingPercentageY= sf::Joystick::getAxisPosition(0, sf::Joystick::Y)/100;

                       //Controll dead area for Y
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
                           if (sf::Joystick::isButtonPressed(0, 5 ))
                           {
                          // player1MovingPercentageX *= dashMultiplier;
                           //player1MovingPercentageY *= dashMultiplier;
                           //std::cout<<"X "<<player1MovingPercentageX * dashMultiplier << "\n";
                           //std::cout<<"Y "<<player1MovingPercentageY * dashMultiplier << "\n";
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


                        /*
                         // CHECK THE PRECENTAGE OF THE PLAYER MOVING SPEED
                        showPosition +=0.005;
                        if (showPosition > 1)
                        {
                            //std::cout<< "Player X precentage= " << player1MovingPercentageX*100<<  " %\n";
                            //std::cout<< "Player Y precentage= " << player1MovingPercentageY *100<< " %\n";
                            showPosition =0;

                        }
                        */



                   window.clear();
                   window.draw(player1);
                   window.display();

               }

    return 0;
}

