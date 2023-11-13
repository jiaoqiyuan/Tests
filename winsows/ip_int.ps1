# param (
#     [string]$inputValue  # 输入值：IP地址或整数
# )


# 将IP地址转换为整数
function Convert-IPToInt {
    param (
        [string]$ipAddress
    )

    $ipBytes = $ipAddress.Split('.')
    [UInt32]$intIP = 0

    for ($i = 0; $i -lt 4; $i++) {
        $intIP = $intIP -shl 8
        $intIP = $intIP -bor [int]$ipBytes[$i]
    }

    return [UInt32]$intIP
}

# 将整数转换为IP地址
function Convert-IntToIP {
    param (
        [UInt32]$intIP
    )

    $ipBytes = @()

    for ($i = 0; $i -lt 4; $i++) {
        $ipBytes += ($intIP -shr ($i * 8)) -band 255
    }

    [array]::Reverse($ipBytes)
    $ipAddress = $ipBytes -join '.'

    return $ipAddress
}


$inputValue = $args[0]
# 判断输入是 IP 地址还是整数
if ($inputValue -match '\d+\.\d+\.\d+\.\d+') {
    # 输入为 IP 地址
    $intResult = Convert-IPToInt -ipAddress $inputValue
    # Write-Host "IP address '$inputValue' convert to integer: $intResult"
    Write-Host $intResult
}
elseif ($inputValue -match '^\d+$') {
    # 输入为整数
    $ipResult = Convert-IntToIP -intIP ([UInt32]$inputValue)
    # Write-Host "Integer '$inputValue' convert to IP: $ipResult"
    Write-Host $ipResult
}
else {
    # Write-Host "无法识别输入。请输入有效的IP地址或整数"
    Write-Host "Cant recognize, please input valid ip or number"
}
