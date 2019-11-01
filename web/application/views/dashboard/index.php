<nav class="navbar navbar-expand-lg navbar-dark bg-dark">
    <div class="container">
        <a class="navbar-brand" href="<?= base_url(); ?>"><strong>Projek IOT</strong></a>
        <button class="navbar-toggler" type="button" data-toggle="collapse" data-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false" aria-label="Toggle navigation">
            <span class="navbar-toggler-icon"></span>
        </button>

        <div class="collapse navbar-collapse" id="navbarSupportedContent">
            <ul class="navbar-nav mr-auto">
                <li class="nav-item">
                    <a class="nav-link" href="#">About</a>
                </li>
                <li class="nav-item">
                    <a class="nav-link" href="#">Graph</a>
                </li>
                <li class="nav-item dropdown">
                    <a class="nav-link dropdown-toggle" href="#" id="navbarDropdown" role="button" data-toggle="dropdown" aria-haspopup="true" aria-expanded="false">
                        Dropdown
                    </a>
                    <div class="dropdown-menu" aria-labelledby="navbarDropdown">
                        <a class="dropdown-item" href="#">Action</a>
                        <a class="dropdown-item" href="#">Another action</a>
                        <div class="dropdown-divider"></div>
                        <a class="dropdown-item" href="#">Something else here</a>
                    </div>
                </li>
                <li class="nav-item">
                    <a class="nav-link disabled" href="#" tabindex="-1" aria-disabled="true">Disabled</a>
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
                <tr class="text-center">
                    <th scope="row"><?= $no  ?></th>
                    <td><?= $data["suhu"]; ?></td>
                    <td><?= $data["kelembapan"]; ?></td>
                    <td><?php date_default_timezone_set('Asia/Jakarta');
                            echo date('m/d/Y H:i:s', $data["waktu"]); ?></td>
                </tr>
                <?php $no++ ?>
            <?php endforeach; ?>
        </tbody>
    </table>
</div>