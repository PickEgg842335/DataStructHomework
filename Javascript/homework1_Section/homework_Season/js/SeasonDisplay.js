
window.onload = function()
{
    let SeasonObj = {
        InputMonthObj: document.getElementById("idSelectMonth"),
        SeasonMsgObj: document.getElementById("idSeasonMsg"),
    }

    SeasonObj = fMonthSelectLoad(SeasonObj);
    sfOutputSeasonMsg(SeasonObj);

    SeasonObj.InputMonthObj.addEventListener("change", function(){
        SeasonObj = fMonthSelectLoad(SeasonObj);
        sfOutputSeasonMsg(SeasonObj);
    });
}


function fMonthSelectLoad(objSeasonTemp)
{
    if(objSeasonTemp.InputMonthObj.length == 1)
    {
        for(AddOptIndex = 1; AddOptIndex <= 12; AddOptIndex++)
        {
            let AddOption = document.createElement("option");
    
            AddOption.value = String(AddOptIndex);
            AddOption.text = String(AddOptIndex);
            objSeasonTemp.InputMonthObj.add(AddOption);
        }
    }
    sfOutputSeasonMsg(objSeasonTemp);
    return(objSeasonTemp);
}


function sfOutputSeasonMsg(objSeasonTemp)
{
    varInputMonth = Number(objSeasonTemp.InputMonthObj.value);
    SeasonMsg = objSeasonTemp.SeasonMsgObj;

    switch(varInputMonth)
    {
        case 12:
        case 1:
        case 2:
            SeasonMsg.innerHTML = `你選的月份是${varInputMonth}月，是冬季`;
            break;
        case 3:
        case 4:
        case 5:
            SeasonMsg.innerHTML = `你選的月份是${varInputMonth}月，是春季`;
            break;
        case 6:
        case 7:
        case 8:
            SeasonMsg.innerHTML = `你選的月份是${varInputMonth}月，是夏季`;
            break;
        case 9:
        case 10:
        case 11:
            SeasonMsg.innerHTML = `你選的月份是${varInputMonth}月，是秋季`;
            break;
        default:
            SeasonMsg.innerHTML = `月份選擇中，請選擇月份`;
            break;
    }
}
