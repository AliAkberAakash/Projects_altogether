for(i=1; i<=9; i++)
        {
            if(a[i]==1)
            {
                if(i==1)
                {
                    if(a[2]==1)
                    {
                        if(a[3]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[3]==0)
                            {
                                a[3]=2;
                                p=true;
                                nothing=false;
                                nothing2=false;
                                break;
                            }
                        }
                    }
                    if(a[3]==1)
                    {
                        if(a[2]==0)
                        {
                            a[2]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                        }
                    }
                    if(a[4]==1)
                    {
                        if(a[7]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[7]==0)
                            {
                            a[7]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                            }
                        }
                    }
                    if(a[7]==1)
                    {
                        if(a[4]==0)
                        {
                            a[4]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                        }
                    }
                    if(a[5]==1)
                    {
                        if(a[9]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[9]==0)
                            {
                            a[9]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                            }
                        }
                    }
                    if(a[9]==1)
                    {
                        if(a[5]==0)
                        {
                            a[5]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                        }
                    }
                }
                if (i==2)
                {
                    if(a[3]==1)
                    {
                        if(a[1]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[1]==0)
                            {
                                a[1]=2;
                                p=true;
                                nothing=false;
                                nothing2=false;
                                break;
                            }
                        }
                    }
                    if(a[1]==1)
                    {
                        if(a[3]==0)
                        {
                            a[3]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                        }
                    }
                   if(a[5]==1)
                    {
                        if(a[8]==1)
                        {
                            player=true;
                            break;
                        }
                        else if(a[8]==0)
                        {
                            a[8]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                        }
                    }
                   if(a[8]==1)
                    {
                        if(a[5]==0)
                        {
                            a[5]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                        }
                    }

                }
                if(i==3)
                {
                    if(a[2]==1)
                    {
                        if(a[1]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[1]==0)
                            {
                            a[1]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                            }
                        }
                    }
                    if(a[1]==1)
                    {
                        if(a[2]==0)
                        {
                            a[2]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                        }
                    }
                    if(a[6]==1)
                    {
                        if(a[9]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[9]==0)
                            {
                            a[9]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                            }
                        }
                    }
                    if(a[9]==1)
                    {
                        if(a[6]==0)
                        {
                            a[6]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                        }
                    }
                    if(a[5]==1)
                    {
                        if(a[7]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[7]==0)
                            {
                            a[7]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                            }
                        }
                    }
                    if(a[7]==1)
                    {
                        if(a[5]==0)
                        {
                            a[5]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                        }
                    }
                }
                else if(i==4)
                {
                    if(a[5]==1)
                    {
                        if(a[6]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[6]==0)
                            {
                            a[6]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                            }
                        }
                    }
                    if(a[6]==1)
                    {
                        if(a[5]==0)
                            {
                            a[5]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                            }
                    }
                    if(a[1]==1)
                    {
                        if(a[7]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[7]==0)
                            {
                                a[7]==2;
                                p=true;
                                nothing=false;
                                nothing2=false;
                                break;
                            }
                        }
                    }
                    if(a[7]==1)
                    {
                        if(a[1]==0)
                            {
                            a[1]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                            }
                    }

                }

                else if(i==5)
                {
                    if(a[6]==1)
                    {
                        if(a[4]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[4]==0)
                            {
                            a[4]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                            }
                        }
                    }
                    if(a[9]==1)
                    {
                        if(a[1]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[1]==0)
                            {
                            a[1]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                            }
                        }
                    }
                    if(a[7]==1)
                    {
                        if(a[3]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[3]==0)
                            {
                            a[3]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                            }
                        }
                    }
                    if(a[8]==1)
                    {
                        if(a[2]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[2]==0)
                            {
                            a[2]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                            }
                        }
                    }
                }
                if(i==7)
                {
                    if(a[8]==1)
                    {
                        if(a[9]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[9]==0)
                            {
                            a[9]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                            }
                        }
                    }
                    if(a[9]==1)
                    {
                        if(a[8]==0)
                            {
                            a[8]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                            }
                    }
                }
                if(i==8)
                {
                    if(a[9]==1)
                    {
                        if(a[7]==1)
                        {
                            player=true;
                            break;
                        }
                        else
                        {
                            if(a[7]==0)
                            {
                            a[7]=2;
                            p=true;
                            nothing=false;
                            nothing2=false;
                            break;
                            }
                        }
                    }
                }
            }

        }