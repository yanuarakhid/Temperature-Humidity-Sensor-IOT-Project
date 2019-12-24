<nav class="navbar navbar-expand-lg navbar-dark bg-dark">
    <div class="container">
        <a class="navbar-brand" href="<?= base_url(); ?>"><strong>Sensor Suhu & Kelembapan</strong></a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>

        <div class="collapse navbar-collapse" id="navbarSupportedContent">
            <ul class="navbar-nav mr-auto">
                <li class="nav-item">
                    <a class="nav-link" href="<?= base_url(); ?>graph">Graph</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="<?= base_url(); ?>about">About Us</a>
                </li>
            </ul>
        </div>
    </div>
</nav>

<div class="container">
    <h1 class="text-center mb-4 mt-4">Sensor SUHU & Kelembaban</h1>
    <table class="table table-striped table-bordered table-hover table-sm">
        <thead>
            <tr class="text-center">
                <th scope="col">No.</th>
                <th scope="col">SUHU</th>
                <th scope="col">KELEMBAPAN</th>
                <th scope="col">Waktu</th>
            </tr>
        </thead>
        <tbody>
            <?php $no = 1 ?>
            <?php foreach ($data as $data) : ?>
            <?php if ($data["suhu"]>=29) :?>
                <tr class="text-center table-danger">
                    <th scope="row"><?= $no  ?></th>
                    <td><?= $data["suhu"]; ?> &#8451;</td>
                    <td><?= $data["kelembapan"]; ?> %</td>
                    <td><?php date_default_timezone_set('Asia/Jakarta');
                        echo date('m/d/Y H:i:s', $data["waktu"]); ?></td>
                </tr>
                <?php elseif ($data["suhu"]<=27) :?>
                    <tr class="text-center table-primary">
                    <th scope="row"><?= $no  ?></th>
                    <td><?= $data["suhu"]; ?> &#8451;</td>
                    <td><?= $data["kelembapan"]; ?> %</td>
                    <td><?php date_default_timezone_set('Asia/Jakarta');
                        echo date('m/d/Y H:i:s', $data["waktu"]); ?></td>
                </tr>
                <?php else :?>
                    <tr class="text-center table-success">
                    <th scope="row"><?= $no  ?></th>
                    <td><?= $data["suhu"]; ?> &#8451;</td>
                    <td><?= $data["kelembapan"]; ?> %</td>
                    <td><?php date_default_timezone_set('Asia/Jakarta');
                        echo date('m/d/Y H:i:s', $data["waktu"]); ?></td>
                </tr>
                <?php $no++ ?>
            <?php endif;?>
            <?php endforeach; ?>
        </tbody>
    </table>
</div>