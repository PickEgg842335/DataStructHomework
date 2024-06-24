function ObjFactor()
{
    this.FactorSource = 0;
    this.FactorValue = [];
};


window.onload = function()
{
    let ObjFactorCal = {
        ObjInput : {
            ObjInputNum : document.getElementById("idInputNum"),
            ObjCalButton : document.getElementById("idCalFactor"),
        },
        ObjFactorMsg : document.getElementById("idFactorMsg"),
    };
    let ObjMyFactor = new ObjFactor();

    sfOutputFactorMsg(ObjFactorCal.ObjFactorMsg, ObjMyFactor);
    ObjFactorCal.ObjInput.ObjInputNum.addEventListener("change", function(){
        sfGetInputFactorValueCheck(ObjFactorCal.ObjInput);
    });
    ObjFactorCal.ObjInput.ObjCalButton.addEventListener("click", function(){
        sfFactorCal(ObjFactorCal, ObjMyFactor);
        sfOutputFactorMsg(ObjFactorCal.ObjFactorMsg, ObjMyFactor);
    });
}


function sfGetInputFactorValueCheck(ObjInputTemp)
{
    let numFactorSrc = Number(ObjInputTemp.ObjInputNum.value);
    let numFactorSrcMin = Number(ObjInputTemp.ObjInputNum.min);

    if(numFactorSrc <= numFactorSrcMin)
    {
        ObjInputTemp.ObjInputNum.value = String(numFactorSrcMin);
        numFactorSrc = numFactorSrcMin;
    }
    else
    {
        ObjInputTemp.ObjInputNum.value = String(Math.floor(numFactorSrc));
    }
}


function sfFactorCal(ObjCalTemp, ObjMyResultTemp)
{
    let numInputSrc = Number(ObjCalTemp.ObjInput.ObjInputNum.value);
    let Calresult = [];

    let index = 0;
    for(let i = 1; i <= numInputSrc; i++)
    {
        if((numInputSrc % i) == 0)
        {
            Calresult[index] = i;
            index++;
        }
    }

    ObjMyResultTemp.FactorSource = numInputSrc;
    ObjMyResultTemp.FactorValue = Calresult;
}


function sfOutputFactorMsg(ObjrMsgTemp, ObjMyResultTemp)
{
    let MyFactorSource = ObjMyResultTemp.FactorSource;

    if(MyFactorSource == 0)
    {
        ObjrMsgTemp.innerHTML = `請輸入<span style="color:red">正整數</span>找出該數值的因數`;
    }
    else
    {
        ObjrMsgTemp.innerHTML = `您的輸入正整數為<span style="color:blue">${MyFactorSource}</span><br>
            其因數共<span style="color:blue">${ObjMyResultTemp.FactorValue.length}</span>個<br>
            因數為:`;
        let index = 0;
        for(let value of ObjMyResultTemp.FactorValue)
        {
            if(index != 0)
            {
                ObjrMsgTemp.innerHTML += ', ';
            }
            ObjrMsgTemp.innerHTML += `<span style="color:blue">${value}</span>`;
            index++;
        }
    }
}
