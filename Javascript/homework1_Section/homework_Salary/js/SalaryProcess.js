const cSalaryRating = {
    HourlySalary : 150,
    OvertimeLevellength : 3,
    OvertimeHourLv : [0, 60, 80],
    OvertimeRatio : [1, 1.25, 1.5],
}

function ObjSalary()
{
    this.NumWorkHour = 0;
    this.NumTotalSalary = 0;
};


window.onload = function()
{
    let ObjSalaryCal = {
        ObjInput : {
            ObjInputhour : document.getElementById("idInputHr"),
            ObjCalButton : document.getElementById("idCalSalary"),
        },
        ObjSalaryMsg : document.getElementById("idSalaryMsg"),
    };
    let ObjMySalary = new ObjSalary();

    sfGetInputHrValueCheck(ObjSalaryCal.ObjInput);
    sfOutputSeasonMsg(ObjSalaryCal.ObjSalaryMsg, ObjMySalary);
    ObjSalaryCal.ObjInput.ObjInputhour.addEventListener("change", function(){
        sfGetInputHrValueCheck(ObjSalaryCal.ObjInput);
    });
    ObjSalaryCal.ObjInput.ObjCalButton.addEventListener("click", function(){
        sfSalaryCal(ObjSalaryCal, ObjMySalary);
        sfOutputSeasonMsg(ObjSalaryCal.ObjSalaryMsg, ObjMySalary);
    });
}


function sfGetInputHrValueCheck(ObjInputTemp)
{
    let numWorkHr = ObjInputTemp.ObjInputhour.value;

    if(numWorkHr <= 0)
    {
        ObjInputTemp.ObjInputhour.value = 0;
        numWorkHr = ObjInputTemp.ObjInputhour.value;
        ObjInputTemp.ObjCalButton.disabled = true;
    }
    else if(numWorkHr > 400)
    {
        ObjInputTemp.ObjInputhour.value = 400;
        numWorkHr = ObjInputTemp.ObjInputhour.value;
        ObjInputTemp.ObjCalButton.disabled = false;
    }
    else
    {
        ObjInputTemp.ObjCalButton.disabled = false;
    }
}


function sfSalaryCal(ObjSalaryCal, ObjPersonSalary)
{
    let PersonWorkHr = ObjSalaryCal.ObjInput.ObjInputhour.value;
    let PersonTotalSalary = 0;
    let lastOvertimeRatio = 0;

    for(let i = 0; i < cSalaryRating.OvertimeLevellength; i++)
    {
        if(PersonWorkHr > cSalaryRating.OvertimeHourLv[i])
        {
            PersonTotalSalary += (cSalaryRating.HourlySalary * (PersonWorkHr - cSalaryRating.OvertimeHourLv[i]))
            * (cSalaryRating.OvertimeRatio[i] - lastOvertimeRatio);
            lastOvertimeRatio = cSalaryRating.OvertimeRatio[i];
        }
        else
        {
            break;
        }
    }
    ObjPersonSalary.NumWorkHour = PersonWorkHr;
    ObjPersonSalary.NumTotalSalary = PersonTotalSalary;
}


function sfOutputSeasonMsg(ObjSalaryMsg, ObjPersonSalary)
{
    let PersonWorkHr = ObjPersonSalary.NumWorkHour;
    let PersonTotalSalary = ObjPersonSalary.NumTotalSalary;

    if(PersonWorkHr == 0)
    {
        ObjSalaryMsg.innerHTML = `請輸入<span style="color:red">工讀時數</span>計算薪資`;
    }
    else
    {
        ObjSalaryMsg.innerHTML = `您的工作時數為<span style="color:red">${PersonWorkHr}</span>小時<br>
        薪資總和為<span style="color:red">${PersonTotalSalary}</span>元`;
    }
}
