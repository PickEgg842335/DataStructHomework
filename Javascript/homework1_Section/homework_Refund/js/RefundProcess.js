const cBanknoteItem = [1000, 500, 100, 50, 10, 5, 1];

function ObjPerChange()
{
    this.RequirePay = 0;
    this.RealPay = 0;
    this.ChangeTotal = 0;
    this.ChangeItemlist = [0, 0, 0, 0, 0, 0, 0,];
};


window.onload = function()
{
    let ObjChangeCal = {
        ObjInput : {
            InputRequirePay : 0,
            ObjRandPayBtn : document.getElementById("idButRandPay"),
            ObjRequirePayMsg : document.getElementById("idSpRandPay"),
            ObjInputRealPay : document.getElementById("idInputRealPay"),
        },
        ObjChangeMsg : document.getElementById("idChangeMsg"),
    };
    let ObjMyChange = new ObjPerChange();
    sfOutputChangeMsg(ObjChangeCal.ObjChangeMsg, ObjMyChange);
    ObjChangeCal.ObjInput.ObjRandPayBtn.addEventListener("click", function(){
        sfGetRandPay(ObjChangeCal.ObjInput);
        sfChangeCal(ObjChangeCal.ObjInput, ObjMyChange);
        sfOutputChangeMsg(ObjChangeCal.ObjChangeMsg, ObjMyChange);
    });
    ObjChangeCal.ObjInput.ObjInputRealPay.addEventListener("change", function(){
        sfGetInputValueCheck(ObjChangeCal.ObjInput);
        sfChangeCal(ObjChangeCal.ObjInput, ObjMyChange);
        sfOutputChangeMsg(ObjChangeCal.ObjChangeMsg, ObjMyChange);
    });
}


function sfGetRandPay(ObjInputTemp)
{
    let RequirePayTemp = Math.floor(Math.random() * 10000) + 1;
    ObjInputTemp.InputRequirePay = RequirePayTemp;
    ObjInputTemp.ObjRequirePayMsg.innerHTML = `${ObjInputTemp.InputRequirePay}`;
    if(RequirePayTemp > 0)
    {
        ObjInputTemp.ObjInputRealPay.disabled = false;
    }
    else
    {
        ObjInputTemp.ObjI9nputRealPay.disabled = true;
    }
}

function sfGetInputValueCheck(ObjInputTemp)
{
    let numRealPay = Number(ObjInputTemp.ObjInputRealPay.value);
    let numRealPayMin = Number(ObjInputTemp.ObjInputRealPay.min);
    let numRealPayMax = Number(ObjInputTemp.ObjInputRealPay.max);

    if(numRealPay <= numRealPayMin)
    {
        ObjInputTemp.ObjInputRealPay.value = String(numRealPayMin);
        numRealPay = numRealPayMin;
    }
    else if(numRealPay > numRealPayMax)
    {
        ObjInputTemp.ObjInputRealPay.value = String(numRealPayMax);
        numRealPay = numRealPayMax;
    }
}


function sfChangeCal(ObjChangeCal, ObjPersonChange)
{
    let numRequirePay = ObjChangeCal.InputRequirePay;
    let numInputRealPay = Number(ObjChangeCal.ObjInputRealPay.value);
    let PersonChange = 0;

    if((numRequirePay != 0) && (numInputRealPay != 0))
    {
        PersonChange = numInputRealPay - numRequirePay;

        ObjPersonChange.RequirePay = numRequirePay;
        ObjPersonChange.RealPay = numInputRealPay;
        ObjPersonChange.ChangeTotal = PersonChange;
        if(PersonChange > 0)
        {
            for(let i = 0; i < ObjPersonChange.ChangeItemlist.length; i++)
            {
                ObjPersonChange.ChangeItemlist[i] = Math.floor(PersonChange / cBanknoteItem[i]);
                PersonChange = PersonChange % cBanknoteItem[i];
                console.log(`${ObjPersonChange.ChangeItemlist[i]} ${PersonChange}`);
            }
        }
        else
        {
            for(let i = 0; i < ObjPersonChange.ChangeItemlist.length; i++)
            {
                ObjPersonChange.ChangeItemlist[i] = 0;
            }
        }
    }
}


function sfOutputChangeMsg(ObjChangeMsg, ObjPersonChange)
{
    let PerequirePay = ObjPersonChange.RequirePay;
    let PerRealPay = ObjPersonChange.RealPay;
    let PerChangeTotal = ObjPersonChange.ChangeTotal;
    let PerChangeItemlist = ObjPersonChange.ChangeItemlist;

    if((PerRealPay == 0) && (PerequirePay == 0) && (PerChangeTotal == 0))
    {
        ObjChangeMsg.innerHTML = `請按下<span style="color:red">取得付款額</span>產生應付金額`;
    }
    else if(PerRealPay == 0)
    {
        ObjChangeMsg.innerHTML = `請輸入<span style="color:red">實付金額</span>計算找零明細`;
    }
    else
    {
        ObjChangeMsg.innerHTML = `您的消費明細如下:<br>
            消費金額:<span style="color:blue">${PerequirePay}</span>元<br>`;
        if(PerRealPay < PerequirePay)
        {
            ObjChangeMsg.innerHTML += `實付金額:<span style="color:red">${PerRealPay}</span>元<br>
            <span style="color:red">付款金額不足</span><br><hr>`;
        }
        else if(PerRealPay == PerequirePay)
        {
            ObjChangeMsg.innerHTML += `實付金額:<span style="color:blue">${PerRealPay}</span>元<br>
                <span style="color:blue">不需找零<br><hr>`;
        }
        else
        {
            ObjChangeMsg.innerHTML += `實付金額:<span style="color:blue">${PerRealPay}</span>元<br>
            找零總額:<span style="color:blue">${PerChangeTotal}</span>元<br>
            <hr>
            找零明細如下:<br>
            ◆&ensp;1000元紙鈔<span style="color:blue">${PerChangeItemlist[0]}</span>張<br>
            ◆&ensp;&ensp;500元紙鈔<span style="color:blue">${PerChangeItemlist[1]}</span>張<br>
            ◆&ensp;&ensp;100元紙鈔<span style="color:blue">${PerChangeItemlist[2]}</span>張<br>
            ◆&ensp;&ensp;&ensp;50元硬幣<span style="color:blue">${PerChangeItemlist[3]}</span>枚<br>
            ◆&ensp;&ensp;&ensp;10元硬幣<span style="color:blue">${PerChangeItemlist[4]}</span>枚<br>
            ◆&ensp;&ensp;&ensp;&ensp;5元硬幣<span style="color:blue">${PerChangeItemlist[5]}</span>枚<br>
            ◆&ensp;&ensp;&ensp;&ensp;1元硬幣<span style="color:blue">${PerChangeItemlist[6]}</span>枚`;
        }
    }
}
