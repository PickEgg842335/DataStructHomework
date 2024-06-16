const cTaipowerEctTab = {
    EctTabNonbine : [
        [0, 1.63, 1.63],
        [120, 2.38, 2.1],
        [330, 3.52, 2.89],
        [500, 4.8, 3.94],
        [700, 5.66, 4.60],
        [1000, 6.41, 5.03],
    ],
    EctTabbine : [
        [0, 2.53, 2.12],
        [330, 3.55, 2.91],
        [700, 4.25, 3.44],
        [1500, 6.43, 5.05],
    ],
    EctTabNonbineLength : 6,
    EctTabbineLength : 4,
}

function ObjPerElect()
{
    this.ElectType = 0;
    this.ElectMonth = 0;
    this.ElectPriceType = 0;
    this.ElectDegree = 0;
    this.ElectPrice = 0;
};


window.onload = function()
{
    let ObjElectCal = {
        ObjInput : {
            ObjInputType : document.getElementById("idInputElectType"),
            ObjInputMonth : document.getElementById("idInputElectMonth"),
            ElectPriceType : 0,
            ObjInputDegree : document.getElementById("idInputElectDegree"),
            ObjCalButton : document.getElementById("idCalElectPrice"),
        },
        ObjElectMsg : document.getElementById("idElectMsg"),
    };
    let ObjMyElect = new ObjPerElect();

    sfGetInputValueCheck(ObjElectCal.ObjInput);
    sfOutputElectMsg(ObjElectCal.ObjElectMsg, ObjMyElect);
    ObjElectCal.ObjInput.ObjInputType.addEventListener("change", function(){
        sfGetInputValueCheck(ObjElectCal.ObjInput);
    });
    ObjElectCal.ObjInput.ObjInputMonth.addEventListener("change", function(){
        sfGetInputValueCheck(ObjElectCal.ObjInput);
    });
    ObjElectCal.ObjInput.ObjInputDegree.addEventListener("change", function(){
        sfGetInputValueCheck(ObjElectCal.ObjInput);
    });
    ObjElectCal.ObjInput.ObjCalButton.addEventListener("click", function(){
        sfElectricityCal(ObjElectCal, ObjMyElect);
        sfOutputElectMsg(ObjElectCal.ObjElectMsg, ObjMyElect);
    });
}


function sfGetInputValueCheck(ObjInputTemp)
{
    let numElectType = Number(ObjInputTemp.ObjInputType.value);
    let numElectMonth = Number(ObjInputTemp.ObjInputMonth.value);
    let numElectDegree = Number(ObjInputTemp.ObjInputDegree.value);
    let numElectDegreeMax = Number(ObjInputTemp.ObjInputDegree.max);
    let numElectDegreeMin = Number(ObjInputTemp.ObjInputDegree.min);
    let boolDegreeChkflag = false;

    if(numElectDegree <= numElectDegreeMin)
    {
        ObjInputTemp.ObjInputDegree.value = String(numElectDegreeMin);
        numElectDegree = numElectDegreeMin;
        boolDegreeChkflag = false;
    }
    else if(numElectDegree > numElectDegreeMax)
    {
        ObjInputTemp.ObjInputDegree.value = String(numElectDegreeMax);
        numElectDegree = numElectDegreeMax;
        boolDegreeChkflag = true;
    }
    else
    {
        boolDegreeChkflag = true;
    }

    if((numElectType != 0) && (numElectMonth != 0) && (boolDegreeChkflag == true))
    {
        if((numElectMonth < 6) || (numElectMonth > 9))
        {
            ObjInputTemp.ElectPriceType = 8;
        }
        else
        {
            ObjInputTemp.ElectPriceType = 4;
        }
        ObjInputTemp.ObjCalButton.disabled = false;
    }
    else
    {
        ObjInputTemp.ObjCalButton.disabled = true;
    }
}


function sfElectricityCal(ObjElectCal, ObjPersonElect)
{
    let numElectType = Number(ObjElectCal.ObjInput.ObjInputType.value);
    let numElectMonth = Number(ObjElectCal.ObjInput.ObjInputMonth.value);
    let numElectDegree = Number(ObjElectCal.ObjInput.ObjInputDegree.value);
    let InputUserType = numElectType + ObjElectCal.ObjInput.ElectPriceType;
    let boolDegreeChkflag = false;
    let PersonTotalElectPrice = 0;
    let lastprice = 0;
    let CurrentTableLength = 0;
    let CurrntMonthType = 0;
    let CurrentEctTable;

    switch(InputUserType)
    {
        case 0x05:
            CurrentTableLength = cTaipowerEctTab.EctTabNonbineLength;
            CurrentTable = cTaipowerEctTab.EctTabNonbine;
            CurrntMonthType = InputUserType >> 2;
            break;
        case 0x06:
            CurrentTableLength = cTaipowerEctTab.EctTabbineLength;
            CurrentTable = cTaipowerEctTab.EctTabbine;
            CurrntMonthType = InputUserType >> 2;
            break;
        case 0x09:
            CurrentTableLength = cTaipowerEctTab.EctTabNonbineLength;
            CurrentTable = cTaipowerEctTab.EctTabNonbine;
            CurrntMonthType = InputUserType >> 2;
            break;
        case 0x0A:
            CurrentTableLength = cTaipowerEctTab.EctTabbineLength;
            CurrentTable = cTaipowerEctTab.EctTabbine;
            CurrntMonthType = InputUserType >> 2;
            break;
    }
    for(let i = 0; i < CurrentTableLength; i++)
    {
        if(numElectDegree > CurrentTable[i][0])
        {
            PersonTotalElectPrice += (numElectDegree - CurrentTable[i][0]) * (CurrentTable[i][CurrntMonthType] - lastprice);
            lastprice = CurrentTable[i][CurrntMonthType];
        }
        else
        {
            break;
        }
    }
    PersonTotalElectPrice = Math.floor((PersonTotalElectPrice + Number.EPSILON) * 10000) / 10000;

    switch(InputUserType)
    {
        case 0x05:
            ObjPersonElect.ElectType = "非營業用電";
            ObjPersonElect.ElectPriceType = "夏月電價";
            console.log(`夏非營`);
            break;
        case 0x06:
            ObjPersonElect.ElectType = "營業用電";
            ObjPersonElect.ElectPriceType = "夏月電價";
            console.log(`夏營`);
            break;
        case 0x09:
            ObjPersonElect.ElectType = "非營業用電";
            ObjPersonElect.ElectPriceType = "非夏月電價";
            console.log(`非夏非營`);
            break;
        case 0x0A:
            ObjPersonElect.ElectType = "營業用電";
            ObjPersonElect.ElectPriceType = "非夏月電價";
            console.log(`非夏營`);
            break;
    }

    ObjPersonElect.ElectMonth = numElectMonth;
    ObjPersonElect.ElectDegree = numElectDegree;
    ObjPersonElect.ElectPrice = PersonTotalElectPrice;
}


function sfOutputElectMsg(ObjElectMsg, ObjPersonElect)
{
    let PerElectType = ObjPersonElect.ElectType;
    let PerlectMonth = ObjPersonElect.ElectMonth;
    let PerElectDegree = ObjPersonElect.ElectDegree;
    let PerElectPriceType = ObjPersonElect.ElectPriceType;
    let PerElectPrice= ObjPersonElect.ElectPrice;

    if((PerlectMonth == 0) || (PerElectType == 0))
    {
        ObjElectMsg.innerHTML = `請輸入<span style="color:red">用電資訊</span>計算電費`;
    }
    else
    {
        ObjElectMsg.innerHTML = `您的電費資訊如下:<br>
        用電戶種類:<span style="color:blue">${PerElectType}</span><br>
        計費月份:<span style="color:blue">${PerlectMonth}</span>月<br>
        電價種類:<span style="color:blue">${PerElectPriceType}</span><br>
        用電度數:<span style="color:blue">${PerElectDegree}</span>度<br>
        用電費用:<span style="color:blue">${PerElectPrice}</span>元`;
    }
}
