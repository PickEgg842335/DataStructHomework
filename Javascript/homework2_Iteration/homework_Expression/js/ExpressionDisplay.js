function ObjExp()
{
    this.ArrayLength = 50;
    this.sum = 0;
};


window.onload = function()
{
    let ObjCalExp = {
        ObjOutput:{
            ObjExpMsg: document.getElementById("idExpMsg"),
        },
    }

    let ObjMyExp = new  ObjExp();

    sfCalExp(ObjCalExp, ObjMyExp);
    sfOutputExpMsg(ObjCalExp.ObjOutput, ObjMyExp);
}


function sfCalExp(objCalTemp, objPersonExp)
{
    let PersonExpSum = 0;
    let PersonArraylength = objPersonExp.ArrayLength;
    let Temp = 1;
    
    for(let i = 1; i <= PersonArraylength; i++)
    {
        PersonExpSum += Temp * i * i;
        Temp = (~Temp + 1);
    }

    objPersonExp.sum = PersonExpSum;
    console.log(`${PersonExpSum}`);
}


function sfOutputExpMsg(objCalExpTemp, objPersonExp)
{
    let PersonArraylength = objPersonExp.ArrayLength;
    let PersonArraySum = objPersonExp.sum;
    let Temp = 1;

    objCalExpTemp.ObjExpMsg.innerHTML = `計算數列共${PersonArraylength}列總和:<br><br>\``;
    for(let i = 1; i <= PersonArraylength; i++)
    {
        let charSigned = '+';
        if((Temp == -1) || (i == 1))
        {
            charSigned = '';
        }
        if(i == 8)
        {
            objCalExpTemp.ObjExpMsg.innerHTML += `‧‧‧\`<br>\``
        }
        else if((i < 8) || (i > (PersonArraylength - 4)))
        {
            objCalExpTemp.ObjExpMsg.innerHTML += charSigned + (Temp * i) + `^2`;
            Temp = (~Temp + 1);
        }
    }
    objCalExpTemp.ObjExpMsg.innerHTML += `=\`<span style="color:blue">\`${PersonArraySum}\`</span>`;
    MathJax.Hub.Typeset();
}
