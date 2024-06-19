function ObjEqsolution()
{
    this.Inputlist = new Array(3);
    this.SolutionType = -1;
    this.Solutionlist = new Array(2);
};


window.onload = function()
{
    let ObjEqCal = {
        ObjInput : {
            objsInputValue : document.getElementsByClassName("classInputEq"),
            ObjCalButton : document.getElementById("idCalEq"),
        },
        ObjEqMsg : document.getElementById("idEqMsg"),
    };
    let ObjMyEqsolution = new ObjEqsolution();
    sfOutputEquationMsg(ObjEqCal.ObjEqMsg, ObjMyEqsolution);
    for(let i = 0; i < ObjEqCal.ObjInput.objsInputValue.length; i++)
    {
        ObjEqCal.ObjInput.objsInputValue[i].addEventListener("change", function(){
            sfGetInputValueCheck(ObjEqCal.ObjInput);
        });
    }
    ObjEqCal.ObjInput.ObjCalButton.addEventListener("click", function(){
        sfEquationCal(ObjEqCal, ObjMyEqsolution);
        sfOutputEquationMsg(ObjEqCal.ObjEqMsg, ObjMyEqsolution);
    });
}


function sfGetInputValueCheck(ObjInputTemp)
{
    let numInputValue = new Array(ObjInputTemp.objsInputValue.length);
    let InputChkbit = false;

    for(let i = 0; i < numInputValue.length; i++)
    {
        numInputValue[i] = ObjInputTemp.objsInputValue[i].valueAsNumber;
        if((numInputValue[i] != 0) && (i == 0))
        {
            InputChkbit = true;
        }
    }

    if(InputChkbit == true)
    {
        ObjInputTemp.ObjCalButton.disabled = false;
    }
    else
    {
        ObjInputTemp.ObjCalButton.disabled = true;
    }
}


function sfEquationCal(ObjEqCal, ObjPersonEq)
{
    let PerInputlistlength = ObjEqCal.ObjInput.objsInputValue.length;
    let PerInputlist = new Array(PerInputlistlength);
    let PerEqSoluationTypeTemp = -1;
    let PerEqSoluationlistTemp = new Array(ObjPersonEq.Solutionlist.length);
    let EigenValue = 0;

    for(let i = 0; i < PerInputlistlength; i++)
    {
        PerInputlist[i] = ObjEqCal.ObjInput.objsInputValue[i].valueAsNumber;
    }

    EigenValue = (PerInputlist[1] * PerInputlist[1]) - (4 * PerInputlist[0] * PerInputlist[2]);
    if(EigenValue < 0)
    {
        PerEqSoluationTypeTemp = 0;
    }
    else if(EigenValue == 0)
    {
        PerEqSoluationTypeTemp = 1;
        PerEqSoluationlistTemp[0] = ((-1) * PerInputlist[1]) / (2 * PerInputlist[0]);
        PerEqSoluationlistTemp[1] = PerEqSoluationlistTemp[0];
    }
    else
    {
        PerEqSoluationTypeTemp = 2;
        EigenValue = Math.sqrt(EigenValue);
        PerEqSoluationlistTemp[0] = (((-1) * PerInputlist[1]) + EigenValue) / (2 * PerInputlist[0]);
        PerEqSoluationlistTemp[1] = (((-1) * PerInputlist[1]) - EigenValue) / (2 * PerInputlist[0]);
    }

    for(let i = 0; i < PerInputlistlength; i++)
    {
        ObjPersonEq.Inputlist[i] = PerInputlist[i];
    }
    ObjPersonEq.SolutionType = PerEqSoluationTypeTemp;

    for(let i = 0; i < ObjPersonEq.Solutionlist.length; i++)
    {
        ObjPersonEq.Solutionlist[i] = Math.floor(PerEqSoluationlistTemp[i] * 100) / 100;
    }
}


function sfOutputEquationMsg(ObjEqMsg, ObjPersonEq)
{
    let PerEqSoluationType = ObjPersonEq.SolutionType;
    let PerInputLength = ObjPersonEq.Inputlist.length;
    let PerInputlist = new Array(PerInputLength);
    let InputEqInnerHtml = ``;
    let PerEqSoluationlist = new Array(ObjPersonEq.Solutionlist.length);
    let CntTemp = 0;
    let CharSignedTemp = '';
    let CharNumTemp = '';
    let CharXTemp = '';
    let MaxZeroFlag = true;

    CntTemp = 0;
    InputEqInnerHtml += '`';
    for(let valueTemp of ObjPersonEq.Inputlist)
    {
        PerInputlist[CntTemp] = valueTemp;
        if(CntTemp == (PerInputLength - 1))
        {
            if(PerInputlist[CntTemp] > 0)
            {
                if(MaxZeroFlag == true)
                {
                    CharSignedTemp = '';
                }
                else
                {
                    CharSignedTemp = '+';
                }
                CharNumTemp = String(PerInputlist[CntTemp]);
                CharXTemp = '';
                MaxZeroFlag = false;
            }
            else if(PerInputlist[CntTemp] < 0)
            {
                CharSignedTemp = '';
                CharNumTemp = String(PerInputlist[CntTemp]);
                CharXTemp = '';
                MaxZeroFlag = false;
            }
            else
            {
                CharSignedTemp = '';
                CharNumTemp = '';
                CharXTemp = '';
            }
        }
        else if(CntTemp == (PerInputLength - 2))
        {
            if(PerInputlist[CntTemp] == 1)
            {
                if(MaxZeroFlag == true)
                {
                    CharSignedTemp = '';
                }
                else
                {
                    CharSignedTemp = '+';
                }
                CharNumTemp = '';
                CharXTemp = 'x';
                MaxZeroFlag = false;
            }
            else if(PerInputlist[CntTemp] == -1)
            {
                CharSignedTemp = '-';
                CharNumTemp = '';
                CharXTemp = 'x';
                MaxZeroFlag = false;
            }
            else if((PerInputlist[CntTemp] > 0) && ((PerInputlist[CntTemp] != 1)))
            {
                if(MaxZeroFlag == true)
                {
                    CharSignedTemp = '';
                }
                else
                {
                    CharSignedTemp = '+';
                }
                CharNumTemp = String(PerInputlist[CntTemp]);
                CharXTemp = 'x';
                MaxZeroFlag = false;
            }
            else if((PerInputlist[CntTemp] < 0) && ((PerInputlist[CntTemp] != -1)))
            {
                CharSignedTemp = '';
                CharNumTemp = String(PerInputlist[CntTemp]);
                CharXTemp = 'x';
                MaxZeroFlag = false;
            }
            else
            {
                CharSignedTemp = '';
                CharNumTemp = '';
                CharXTemp = '';
            }
        }
        else if(CntTemp == (PerInputLength - 2))
        {
            if(PerInputlist[CntTemp] == 1)
            {
                if(MaxZeroFlag == true)
                {
                    CharSignedTemp = '';
                }
                else
                {
                    CharSignedTemp = '+';
                }
                CharNumTemp = '';
                CharXTemp = 'x';
                MaxZeroFlag = false;
            }
            else if(PerInputlist[CntTemp] == -1)
            {
                CharSignedTemp = '-';
                CharNumTemp = '';
                CharXTemp = 'x';
                MaxZeroFlag = false;
            }
            else if((PerInputlist[CntTemp] > 0) && ((PerInputlist[CntTemp] != 1)))
            {
                if(MaxZeroFlag == true)
                {
                    CharSignedTemp = '';
                }
                else
                {
                    CharSignedTemp = '+';
                }
                CharNumTemp = String(PerInputlist[CntTemp]);
                CharXTemp = 'x';
                MaxZeroFlag = false;
            }
            else if((PerInputlist[CntTemp] < 0) && ((PerInputlist[CntTemp] != -1)))
            {
                CharSignedTemp = '';
                CharNumTemp = String(PerInputlist[CntTemp]);
                CharXTemp = 'x';
                MaxZeroFlag = false;
            }
            else
            {
                CharSignedTemp = '';
                CharNumTemp = '';
                CharXTemp = '';
            }
        }
        else if(CntTemp == 0)
        {
            if(PerInputlist[CntTemp] == 1)
            {
                CharSignedTemp = '';
                CharNumTemp = '';
                CharXTemp = `x^${PerInputLength - 1 - CntTemp}`;
                MaxZeroFlag = false;
            }
            else if(PerInputlist[CntTemp] == -1)
            {
                CharSignedTemp = '-';
                CharNumTemp = '';
                CharXTemp = `x^${PerInputLength - 1 - CntTemp}`;
                MaxZeroFlag = false;
            }
            else if((PerInputlist[CntTemp] > 0) && ((PerInputlist[CntTemp] != 1)))
            {
                CharSignedTemp = '';
                CharNumTemp = String(PerInputlist[CntTemp]);
                CharXTemp = `x^${PerInputLength - 1 - CntTemp}`;
                MaxZeroFlag = false;
            }
            else if((PerInputlist[CntTemp] < 0) && ((PerInputlist[CntTemp] != -1)))
            {
                CharSignedTemp = '';
                CharNumTemp = String(PerInputlist[CntTemp]);
                CharXTemp = `x^${PerInputLength - 1 - CntTemp}`;
                MaxZeroFlag = false;
            }
            else
            {
                CharSignedTemp = '';
                CharNumTemp = '';
                CharXTemp = '';
            }
        }
        else
        {
            if(PerInputlist[CntTemp] == 1)
            {
                if(MaxZeroFlag == true)
                {
                    CharSignedTemp = '';
                }
                else
                {
                    CharSignedTemp = '+';
                }
                CharNumTemp = '';
                CharXTemp = `x${PerInputLength - 1 - CntTemp}`;
                MaxZeroFlag = false;
            }
            else if(PerInputlist[CntTemp] == -1)
            {
                CharSignedTemp = '-';
                CharNumTemp = '';
                CharXTemp = `x${PerInputLength - 1 - CntTemp}`;
                MaxZeroFlag = false;
            }
            else if((PerInputlist[CntTemp] > 0) && ((PerInputlist[CntTemp] != 1)))
            {
                if(MaxZeroFlag == true)
                {
                    CharSignedTemp = '';
                }
                else
                {
                    CharSignedTemp = '+';
                }
                CharNumTemp = String(PerInputlist[CntTemp]);
                CharXTemp = `x${PerInputLength - 1 - CntTemp}`;
                MaxZeroFlag = false;
            }
            else if((PerInputlist[CntTemp] < 0) && ((PerInputlist[CntTemp] != -1)))
            {
                CharSignedTemp = '';
                CharNumTemp = String(PerInputlist[CntTemp]);
                CharXTemp = `x${PerInputLength - 1 - CntTemp}`;
                MaxZeroFlag = false;
            }
            else
            {
                CharSignedTemp = '';
                CharNumTemp = '';
                CharXTemp = '';
            }
        }
        InputEqInnerHtml += CharSignedTemp + CharNumTemp + CharXTemp;
        CntTemp++;
    }
    InputEqInnerHtml += '=0`';

    CntTemp = 0;
    for(let valueTemp of ObjPersonEq.Solutionlist)
    {
        PerEqSoluationlist[CntTemp] = valueTemp;
        CntTemp++;
    }

    switch(PerEqSoluationType)
    {
        case -1:
            ObjEqMsg.innerHTML = `請輸入二元一次方程式\`ax^2+bx+c=0\`之\`a\`,\`b\`,\`c\`參數。按下計算求\`x\`解`;
            break;
        case 0:
            ObjEqMsg.innerHTML = `您輸入的方程式為\ ${InputEqInnerHtml}<br><br>
                \`b^2-4ac\`<span style='color:red;'>\`<\`</span>\`0\`<br><br>
                <span style='color:red;'>無實數解</span>`;
            break;
        case 1:
            ObjEqMsg.innerHTML = `您輸入的方程式為\ ${InputEqInnerHtml}<br><br>
                \`b^2-4ac\`<span style='color:red;'>\`=\`</span>\`0\`<br><br>
                <span style='color:red;'>有兩個相等的實根</span>, 實根為<span style='color:red;'>${PerEqSoluationlist[0]}</span>`;
            break;
        case 2:
            ObjEqMsg.innerHTML = `您輸入的方程式為\ ${InputEqInnerHtml}<br><br>
                \`b^2-4ac\`<span style='color:red;'>\`>\`</span>\`0\`<br><br>
                <span style='color:red;'>有兩個相異的實根</span>, 實根為<span style='color:red;'>${PerEqSoluationlist[0]}</span>與<span style='color:red;'>${PerEqSoluationlist[1]}</span>`;
            break;
        default:
            break;
    }
    MathJax.Hub.Typeset();
}
