function ObjLeapYear()
{
    this.BoolLeapYear = 0;
    this.NumYear = 0;
};


window.onload = function()
{
    let ObjLeapYearCal = {
        ObjInput : {
            ObjInputYear : document.getElementById("idInputYear"),
            ObjCalButton : document.getElementById("idCalleepYear"),
        },
        ObjYearMsg : document.getElementById("idLeapYearMsg"),
    };
    let ObjMyLeapYear = new ObjLeapYear();

    sfGetInputYearValueCheck(ObjLeapYearCal.ObjInput);
    sfOutputLeapYearMsg(ObjLeapYearCal.ObjYearMsg, ObjMyLeapYear);
    ObjLeapYearCal.ObjInput.ObjInputYear.addEventListener("change", function(){
        sfGetInputYearValueCheck(ObjLeapYearCal.ObjInput);
    });
    ObjLeapYearCal.ObjInput.ObjCalButton.addEventListener("click", function(){
        sfLeapYearCal(ObjLeapYearCal, ObjMyLeapYear);
        sfOutputLeapYearMsg(ObjLeapYearCal.ObjYearMsg, ObjMyLeapYear);
    });
}


function sfGetInputYearValueCheck(ObjInputTemp)
{
    let numYear = Number(ObjInputTemp.ObjInputYear.value);
    let numYearMin = Number(ObjInputTemp.ObjInputYear.min);

    if(numYear <= numYearMin)
    {
        ObjInputTemp.ObjInputYear.value = String(numYearMin);
        numYear = numYearMin;
        ObjInputTemp.ObjCalButton.disabled = true;
    }
    else
    {
        ObjInputTemp.ObjCalButton.disabled = false;
    }
}


function sfLeapYearCal(ObjLeapYearCal, ObjPersonLeapYear)
{
    let numYear = Number(ObjLeapYearCal.ObjInput.ObjInputYear.value);
    let PersonLeapYear = 0;

    PersonLeapYear = ((((numYear % 4) == 0) && ((numYear % 100) != 0)) || ((numYear % 400) == 0)) 
        && ((numYear % 4000) != 0);

    ObjPersonLeapYear.NumYear = numYear;
    switch(PersonLeapYear)
    {
        case false:
            ObjPersonLeapYear.BoolLeapYear = "非閏年";
            break;
        case true:
            ObjPersonLeapYear.BoolLeapYear = "閏年";
            break;
    }
}


function sfOutputLeapYearMsg(ObjLeapYearMsg, ObjPersonLeapYear)
{
    let PersonBoolLeapYear = ObjPersonLeapYear.BoolLeapYear;
    let PersonNumYear = ObjPersonLeapYear.NumYear;

    if(PersonNumYear == 0)
    {
        ObjLeapYearMsg.innerHTML = `請輸入<span style="color:red">西元年</span>計算是否為閏年`;
    }
    else
    {
        ObjLeapYearMsg.innerHTML = `您的輸入為西元<span style="color:red">${PersonNumYear}</span>年，
        該年為<span style="color:red">${PersonBoolLeapYear}</span>`;
    }
}
