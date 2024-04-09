# ddsflow

ddsflow 是一个独立的进程，是一个 dds 客户端，是一个 libflow 的服务端。
会读取 dds 中的数据，并通过 libflow 发送出去。

## 依赖

```
libdds.so
libdds_api.so
libnanomsg.so
libflow.so
```

## 使用

现在release中的压缩包文件，直接放在板子上

```bash
./ddsflow config.json
```

程序运行起来之后，会自动把 `config.json` 中指定的 topic 从 dds 转发到 libflow。

## 配置文件格式

格式基本和 dds 的配置文件一致，多了 `flow_addr` 和 `flow_port` 两个属性。

```json
{
  "log_level": 1,
  "topics": [
    {
      "topic": "adas",
      "dds_mode": "shm",
      "buff_num": 100,
      "elem_max_size": 1000000
    }
  ],
  "flow_addr": "127.0.0.1",
  "flow_port": 24012
}
```

## t1q板子上的使用
将ddsflow/build/tda4、dds_pub.sh、dds2flow.sh、config拷贝到板子上，修改config中dds2flow.json使其ip与板子ip相同，修改本机上libflow_sub.sh中的ip与板子ip相同。

在板子上运行dds_pub.sh发送dds消息，运行dds2flow.sh在板子上将消息转发到libflow，在本机上运行libflow_sh.sh订阅libflow中的消息并进行转发。

